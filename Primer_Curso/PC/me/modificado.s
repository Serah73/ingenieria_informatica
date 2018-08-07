# #include <iostream>
# using namespace std;
#
# int main(void)
# {
#     const int m =4; //filas de la matriz
#     const int n =5; //col de la matriz
#	
#     int matriz [m][n] = {{1,2,3,4,5},
#                          {2,3,4,5,6},
#                          {3,4,5,6,7},
#                          {4,5,6,7,8}};
#
#  	  int col, aux=0;  //columna a mostrar
#     cout<<"Introduzca la columna:";
#     cin>>col;
#     bool ordenada=true;
#     int i=0;
#     while((i<m-1) && ordenada)
# 	  {
#         if(matriz[i][col]<=matriz[i+1][col]){
#             i++;
#	      if(matriz[i][col]<aux)
#		aux=matriz[i][col]
#	  }
#         else {
#             cout << "desordenada" << endl;
#             ordenada=false;
#         }
# 	  }
#     if (ordenada)
#             cout << "ordenada" << endl;
# }








nfil=4              #numero de filas
ncol=5              #numero de columnas
size=4              #tamaño de los elementos del vector

        .data
matriz:     .word   1, 2, 3, 4, 5
            .word   2, 3, 4, 5, 6
            .word   3, 4, 5, 6, 7
            .word   4, 5, 6, 7, 5
cadena1 :    .asciiz "ordenada\n"
cadena2 :    .asciiz "desordenada\n"
cadena3 :    .asciiz "Introduzca la columna a procesar:"
cadena4 :    .asciiz "el valor mas pequeño encontrado es:"
        .text
main:
	    li $s1,1000	      # aux inicialmente a 1000 para que salte el if2
            li $v0,4          # print_string
            la $a0, cadena3   # std::cout<<"introduzca la columna a procesar:"<<std::endl
            syscall
            li $v0,5          # leer un int
            syscall
            move $s0, $v0     # Pasa el valor de $v0 a $s0 para evitar que varie, col a comprobar
            la $a0, matriz
            li $t0,0          # inicializamos i=0
          ###  li $t1,1          #inicializamos el bool como TRUE=1)
            li $t2,3          # inicializamos (nfil-1) para el while
          ###  li $t6,nfil       # inicializamos el numero de filas
            li $t3,ncol       # inicializamos el numero de columnas
while:      bge $t0,$t2, endw
          ###  bne $t1,1, endw
            la $t4, matriz    # cargamos dirrecion base
            mul $t5, $t0, $t3 # i*ncol
            add $t5, $t5, $s0 # i*ncol+col
            mul $t5, $t5, 4   # (i*ncol+col)*size
            add $t5, $t5, $t4 # dirrecion del elemento matriz[i][col]
            lw $t7, 0($t5)    # Tenemos el valor de matriz[i][col] en $t7
            
            add $t9, $t0, 1   # $t9=i+1
            
            la $t4, matriz    # cargamos dirrecion base
            mul $t5, $t9, $t3 # i*ncol
            add $t5, $t5, $s0 # i*ncol+col
            mul $t5, $t5, 4   # (i*ncol+col)*size
            add $t5, $t5, $t4 # dirrecion del elemento matriz[i][col]
            lw $t8, 0($t5)    # Tenemos el valor de matriz[i+1][col] en $t8


if:         bgt $t7, $t8, endif     #$t7>$t8 salta a endif
            addi $t0, 1     # i++
if2:        bge $t7, $s1, endif2
	    move $s1, $t7
endif2:     j while
            
endif:      li $v0, 4
            la $a0, cadena2     # std::cout<<"desordenada"<<std::endl
            syscall
          ###  li $t1, 0
            j enda
endw:       li $v0, 4
            la $a0, cadena1 # cout<<ordenada
            syscall
enda: 	    li $v0, 4
            la $a0, cadena4
	    syscall
	    li $v0, 1
	    move $a0, $s1
	    syscall
            li $v0, 10
            syscall
