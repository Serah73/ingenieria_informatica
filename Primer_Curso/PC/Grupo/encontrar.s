

nfil=3              #numero de filas
ncol=3              #numero de columnas
size=4              #tamaño de los elementos del vector

        .data
matriz:     .word   1, 2, 3
            .word   4, 5, 6
            .word   8, 9, 7

cadena1 :    .asciiz "es el:"
cadena2 :    .asciiz "i:"	
cadena3 :    .asciiz "j:"
        .text

main:
            li $v0,4          # print_string
            la $a0, cadena2   # std::cout<<"i:"<<std::endl
            syscall
            li $v0,5          # leer un int
            syscall
            move $s0, $v0     # Pasa el valor de $v0 a $s0 para evitar que varie, col a comprobar
            
            li $v0,4          # print_string
            la $a0, cadena3   # std::cout<<"j:"<<std::endl
            syscall
            li $v0,5          # leer un int
            syscall
            move $s1, $v0     # Pasa el valor de $v0 a $s1 para evitar que varie, col a comprobar
            
	        la $a1, matriz
            li $t2,nfil       
            li $t1,0	      #indice j=0
            li $t3,ncol       # inicializamos el numero de columnas
  
            la $t4, matriz    # cargamos dirrecion base
            mul $t5, $s0, $t3 # i*ncol
            add $t5, $t5, $s1 # i*ncol+j
            mul $t5, $t5, 4   # (i*ncol+j)*size
            add $t5, $t5, $a1 # dirrecion del elemento matriz[i][j]
            lw $t6, 0($t5)    # Tenemos el valor de matriz[i][j] en $t6
	    
	    li $v0, 4
            la $a0, cadena1
            syscall
      
            li	$v0,1
	    move $a0,$t6
	    syscall
	    li $v0,5
	    syscall
	   

enda:       li $v0, 10
            syscall






