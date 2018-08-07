# PROGRAMA QUE REALIZA UNA BUSQUEDA LINEAL DE UN ELEMENTO
# EN UN VECTOR.

size = 4		# tamano de los elementos del vector
N = 10			# numero de elementos del vector
			.data
vector:			.word	2, 3, 5, 6, 8, 1, 3, 2, 5, 9	
abuscar:		.word	6        # modifica este valor para que pruebes diferentes busquedas
encontrado:		.word   0	     # tras la ejecucion en Qtspim inspecciona esta posicion de memoria
					             # para comprobar el resultado
cadinicio:      .asciiz     "Vamos a recorrer el vector en busca de un elemento\n";
cadfound:       .asciiz     "\nSe ha encontrado el elemento en el vector en la posición: ";
cadnfound:      .asciiz     "\nNo se ha encontrado el elemento en el vector\n";
men:				.asciiz		"\nEl mayor es:\n";
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
			beq $v0, $zero, else		# si $v0=$zero salta al "else"
			li  $v0, 4                  #  imprimir string
			la $a0, cadfound            #  el string a imprimir es "cadfound"
			syscall
			
			li $v0, 1		# imprimir int
			move $a0, $v1	# el entero a imprimir es la posicion donde lo encontro
			syscall
			
			li $v0, 4
			la $a0, men
			syscall			# el mayor es...
			
			li $v0, 1
			move $a0, $t3
			syscall

			b endif1
		else:
		    li $v0, 4                   # imprimir string
			la $a0, cadnfound           # el string a imprimir es "cadnfound"
			syscall
		endif1:
			# salida limpia del sistema
			li	$v0,10
			syscall
# FIN DEL PROGRAMA PRINCIPAL

        # bilineal:
		# funcion blinealR: 	$a0 direccion base del vector
        #                       $a1 numero de elementos del vector a buscar
        #			            $a2 elemento buscado
        #	      devuelve:	    $v0 = 1 si encontra el elemento $v0 = 0 en caso contrario
        #
		#INTRODUCE COMO COMENTARIO EL PSEUDOC�DIGO O EL PROGRAMA EN LENG. ALTO NIVEL
		#
		# int blineal(int* vector, int N, int abuscar){
		#	for(i=0;i<N;i++){		
		#   		if(vector[i] == abuscar){
		#                  	return 1;
		# 		}
		#   }
        #	return 0;
		# }

   # INTRODUCE AQUI EL C�DIGO DE TU SUBRUTINA
blineal:
    move $t1, $a0
    li $t0, 0   # contador en $t0
    li $t3, 0	# contador del mayor
for:
    bge $t0, $a1, endfor		# si $t0>=$a1 salta a endfor
    lw $t2, 0($t1)              # vector[i] en $t2
if:
    bne $a2, $t2, endif         # si $a2!=$t2 salta a endif  (si vector[i] != abuscar) 
    li $v0, 1	                # devolvemos un 1 en $v0 
    move $v1, $t0
    jr $ra                      # Vuelve a la donde lo había dejado en el main
endif:
	ble $t2, $t3, pasa
	move $t3, $t2
pasa:
    addi $t0, 1			        # i++
    addi $t1, 4				    # siguiente posicion del vector
    b for
endfor:
    li $v0, 0
    jr $ra                      # Vuelve a la donde lo había dejado en el main