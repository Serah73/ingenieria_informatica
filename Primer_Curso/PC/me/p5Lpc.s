# PROGRAMA QUE REALIZA UNA B�SQUEDA LINEAL DE UN ELEMENTO
# EN UN VECTOR.

size = 4		# tamano de los elementos del vector
N = 10			# numero de elementos del vector
			.data
vector:			.word	2, 3, 5, 6, 8, 1, 3, 2, 5, 9	
abuscar:		.word	6        # modifica este valor para que pruebes diferentes busquedas
encontrado:		.word   0	 # tras la ejecucion en Qtspim inspecciona esta posicion de memoria
					 # para comprobar el resultado
cadinicio:      .asciiz     "Vamos a recorrer el vector en busca de un elemento\n";
cadfound:       .asciiz     "\nSe ha encontrado el elemento";
cadnfound:      .asciiz     "\nNo se ha encontrado el elemento en el vector\n";

			.text
main:
            li  $v0, 4
            la  $a0, cadinicio
            syscall
            
			la	$a0,vector    	# primer parametro la direccion base del vector
			li	$a1,N		    # segundo parametro el numero de elementos del vector
			lw	$a2,abuscar     # tercer parametro el elemento a buscar
			jal	blineal     	# quedara en $v0 1 si lo encontro 0 en caso contrario
			sw	$v0,encontrado  # almacenamos en resultado de busqueda en una posicion de memoria
			
		if1:
			beq $v0, $zero, else1		# si $v0=$zero salta al "else"
			li  $v0, 4                  #  imprimir string
			la $a0, cadfound            #  el string a imprimir es "cadfound"
			syscall

			b endif1
		else1:
		    li $v0, 4                   # imprimir string
			la $a0, cadnfound           # el string a imprimir es "cadnfound"
			syscall
		endif1:
			# salida limpia del sistema
			li	$v0,10
			syscall
# FIN DEL PROGRAMA PRINCIPAL


		# funcion blinealR: 	$a0 direccion base del vector
        #               		$a1 numero de elementos del vector a buscar
        #		 	    		$a2 elemento buscado
        #	devuelve:		$v0 = 1 si encontra el elemento $v0 = 0 en caso contrario
		#  INTRODUCE COMO COMENTARIO EL PSEUDOC�DIGO O EL PROGRAMA EN LENG. ALTO NIVEL
		#	int blineal(int* vector, int N, int abuscar){ 
		#		if(N == 0){
		#			return 0;		//no encontrado
		#		}
		#		else if(vector[0] == abuscar){
		#			return 1;
		#		}
		#		else {
		#			return(blineal(&vector[1], N-1, abuscar));
		#		}
		#	}
# para la direccion es sumarle size a $a0 y el tama�o es restarle uno al $a1
# addi $a0, size
# addi $a1, -1
# llamada recursiva de la funcion

   # INTRODUCE AQUI EL C�DIGO DE TU SUBRUTINA
blineal:

if:
	bne $a1, $zero, elsif		# si $a1!=$zero salta a elsif
    li $v0, 0					# devulve 0
    jr $ra
elsif:
	lw $t0, 0($a0)				# ponemos en $t0 vector[0]
    bne $a2, $t0, else          # comparamos la direccion base con el elemento buscado ($a2 != $t0) 
    li $v0, 1	                # devolvemos un 1 en $v0 
    jr $ra                      # Vuelve a la donde lo había dejado
else:
	addi $sp, -12				# reservamos espacio para 2 enteros en la pila
	sw $a0, 0($sp)				# direccion base(que depende de en que llamada esta) guardada en pila
	sw $a1, 4($sp)				# numero de elementos del vector de esta llamada guardada en la pila
	sw $ra, 8($sp)				# guardamos la direccion de retorno en la pila
	
	addi $a0, 4					# pasamos a la siguiente casilla del vector
	addi $a1, -1				# restamos "1" al numero de elementos del vector
	
	jal blineal					# volvemos a llamar a la funcion
	
	lw $a0, 0($sp)				# cargamos la antigua direccion base del vector al registro $a0
	lw $a1, 4($sp)				# cargamos el tamaño anterior al registro $a1
	lw $ra, 8($sp)				# cargamos la antigua direccion de retorno
	addi $sp, 12				# sumamos 8 al puntero de pila
	
	jr $ra						# vuelve a la direccion de retorno