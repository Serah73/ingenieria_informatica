#include<iostream>
#using namespace std;
#
#
#int main(void){
#	int c=10;
#	float n, suma, media;
#	cout<<"Introd. 10 numeros a continuacion";
#	for(int i=0; i<c; i++){
#		cout<<"introd. un numero:";
#		cin<<n;
#		cout<<endl;
#		suma+=n;
#	}
#	media= suma/c;
#	cout<<"media"<<endl;
#}
#
# Para las variableas usaremos los siguientes registros:

# La variable int i corresponderá a $t0
# La variable int c corresponderá a $t1
# La variable float n corresponderá a $f4
# la variable float suma corresponderá a $f6
# la variable float media corresponderá a $f8

	.data

cadena.inicio:		.asciiz "\n Introd. 10 numeros a continuacion";
cadena.ciclo:		.asciiz "\n Introd. un numero:";
fin.cadena:			.asciiz "\n la media es:";


	.text
main:
	
		li $v0 ,4				#le decimos que vamos hacer un print de un string
		la $a0 ,cadena.inicio 			#le decimos que en $a0 esta cadena.inicio ya que el comando li $v0,4 buscara en ese registro el string
		syscall					#llamamos al "compilador" para que ejecute los comandos introducidos

		li $t0, 0				#inicializamos el valor a 0 para el bucle for
		li $t1,10				#damos valor a c=10(numeros que pedimos para la media) 
		li.s $f6,0.0				#inicializar el registro a 0
		li.s $f4,0.0				#inicializar el registro a 0

buclefor:	bge $t0,$t1, finbucle			#si $t0 es mayor que $t1 salta a finbucle.
		li $v0 ,4				#print_string
		la $a0 ,cadena.ciclo			#print_string de cadena.ciclo
		syscall	
		li $v0 ,6
		syscall		#read_float
		mov.s $f4,$f0				#mover a $f4 el contenido de $v0
		add.s $f6,$f6,$f4  			#sumar en punto simple $f6 y $f4, guardandolo en $f6
		addi $t0,1 				#i++	
		li.s $f4,0.0				#inicializar el registro a 0
		
		j buclefor

finbucle:	mtc1 $t1,$f16				#copia en crudo
		cvt.s.w $f18,$f16			#ahora lo pasamos al IEEE754
		li $v0, 2
		mov.s $f12, $f6
		syscall
		div.s $f8,$f6,$f18			#media=suma/c 
		li $v0, 4
		la $a0, fin.cadena
		syscall
		li $v0, 2				#print_float
		mov.s $f12, $f8
		syscall
		li $v0, 10
		syscall
#END
