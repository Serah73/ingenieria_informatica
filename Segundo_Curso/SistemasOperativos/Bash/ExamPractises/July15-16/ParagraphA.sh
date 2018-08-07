#ENUNCIADO CONVOCATORIA JULIO "a)":

#   Sacar un listado con todos los procesos del sistema ordenados primero por el número de fallos de página
#mayores y después por el de menores

#////////////3 ptos.///////////////

#!/bin/bash

#vamos a usar el comando ps, opciones a tener en cuenta "--sort 'campo' " "-o 'campos a ver separados por comas y pegado sin espacios' "

numero_proceso()
{
    echo "$(ps -A -ocmd --sort min_flt --no-headers | head -n $1)"
}



if [ $1 == "" ]; then
    echo "listado de procesos ordenados de menor a mayor fallo de pagina"
    echo "$(ps -A -ocmd --sort min_flt --no-headers)"

    echo "listado de procesos ordenados de mayor a  menor fallo de pagina"
    echo "$(ps -A -ocmd --sort maj_flt --no-headers)"

else
    case $1 in 
        
        -numP ) shift
                numero_proceso $@
                shift
                ;;
        
        -Time ) shift
                tiempo_proceso $@
                shift
                ;;
                
        * )     echo "Has introducido una opcion invalida, no queremos cojos"
                ;;
    esac
fi