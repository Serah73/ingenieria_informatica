#   #include<iostream>
#   void mover(int* v, int a, int b)
#   {
#       int c, d;
#       for(int i=0;i<5;i++)
#       {
#            if(i==a)
#                c=v[i];
#            if(i==b)
#                d=v[i];
#        }
#        for(int i=0;i<5;i++)
#        {
#            if(i==a)
#                v[i]=d;
#            if(i==b)
#                v[i]=c;
#        }
#   }
#
#   int main(void)
#   {
#     int a, b;
#     int v[5]={1, 2, 3, 4, 5};
#     std::cout<<"posicion 1"<<std::endl;
#     std::cin>>a;
#     std::cout<<"posicion 2"<<std::endl;
#     std::cin>>b;
#     mover(v, a, b);
#     for(int i=0; i<5; i++)
#     {
#         std::cout<<v[i]<<","<<" "<<std::endl;
#     }
#     return (0);
#   }
            .data
vector:         .word       1 ,2, 3, 4, 5
cadena1:        .asciiz     "\n Introduzca la primera posicion: "
cadena2:        .asciiz     "\n Intraduzca la segunda posicion: "

            .text
main:
        li $t4, 0  # i para el for
#   LEER A
        li $v0, 4               #primer numero
        la $a0, cadena1
        syscall
        li $v0, 5
        syscall
        move $t0, $v0           # En $t0 esta a
#   LEER B
        li $v0, 4               #segundo numero
        la $a0, cadena2         
        syscall
        li $v0, 5
        syscall
        move $t1, $v0           # En $t1 esta b
        
        la $a1, vector
        move $a0, $t0
        move $a2, $t1
        j mover
        
for:    bge $t4, 5, fin
        li $v0, 1
        lw $t1, 0($a1)
        move $a0, $t1
        syscall
        add $a1, $a1, 4
        addi $t4, 1
        j for
        
fin:    li $v0, 10
        syscall
        
        
        
mover:  
        mul $a0, $a0, 4
        add $a0, $a0, $a1   # ahora tenemos la direccion base de A
        mul $a2, $a2, 4
        add $a2, $a2, $a1   # ahora tenemos la direccion base de B
        lw $t2, 0($a0)      # el valor de A esta en $t2
        lw $t3, 0($a2)      # el valor de B esta en $t3
        sw $t2, 0($a2)      # guardamos el dato de A en B
        sw $t3, 0($a0)      # guardamos el dato de B en A
        j for
