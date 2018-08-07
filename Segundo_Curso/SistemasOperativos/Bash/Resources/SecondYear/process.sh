#!/bin/bash

#Usando lo aprendido hasta el momento en clase, desarrolla el script 'process' que, si no se especifica opción,
#muestre un listado de todos los procesos
#en el sistema que incluya: el nombre del proceso, el propietario, el PID, el tiempo de uso de cpu,
#la prioridad del proceso, el cálculo de la relación
#entre memoria residente y la necesidad de memoria de intercambio necesaria para almacenar el proceso en caso de
#suspenderlo y el propietario del proceso.
#El cálculo de la relación debe hacerse de forma decimal. (Se puede utilizar el comando BC para cálculos decimales,
#ejemplo echo “1/4” | bc -l ).


#################################################################################################################
#El listado deberá estar ordenado por tiempo de ejecución de CPU y con el parámetro -R la ordenación será inversa
#################################################################################################################

#Añadir la opción -user para mostrar los procesos de un conjunto de usuarios separados por espacios.

#Añadir la opcion -nice a b, donde se procesarán solo los procesos con priorididad entre a y b.

#Añadir la opcion -inc n que permitirá aumentar en n unidades la prioridad de los procesos previamente seleccionados.

#Añadir la opcion -dec n que permitirá reducir en n unidad la prioridad de los procesos previamente seleccionados.

#Añadir la opción -filter “exp_regular”, donde se indicará que procesos gestionar a través de una expresión regular

#Todos los parámetros pueden ser utilizados de manera simultanea.

#ZONA DE VARIABLES
FLAG_USER=$(tempfile --prefix="tmp" --suffix=".USERPRO.$$")
USERON=
VARUSER=
NICEON=
FILTERON=
INC=
DEC=
SIZE=
RESULTDIV=
COUNT=
ON=
ANICE=
BNICE=
CMD=
FILTER=
PROGNAME=$(basename $0)

#ZONA FUNCION
error_exit()
{
    echo "${PROGNAME}: ${1:-"Error desconocido"}" 1>&2
    exit 1
}



sin_opcion()            ###no me hace la division y me muestra el size y vsize
{
    echo "Funcion por defecto"
    for palabra in $(ps --no-headers -Ao user,pid,fname,time,ni,size,vsize | tr -s " "); do
        if [[ "$COUNT" != 7 ]] && [[ "$COUT" != 6 ]]; then
	   	    printf "%s\t" "$palabra"
	    fi
	    
        if [[ "$COUNT" == 6 ]]; then
        	SIZE=$palabra
        fi
        
        if [[ "$COUNT" == 7 ]]; then
        
            if [[ $palabra == 0 ]]; then
                printf "NaN \n"
        
            else
        	    RESULTDIV=$(( SIZE / palabra ))
		        printf "%s\n" "$RESULTDIV"
	        fi
	      fi
	    COUNT=$((COUNT + 1))
	    
	    if [[ "$COUNT" == 8 ]]; then
	         COUNT=1
	    fi
    done
}


principal()
{
    if [[ "$USERON" = 1 ]];then

        for userfor in $( cat $FLAG_USER ); do
############user y nice        
            if [[ "$NICEON" = 1 ]] && [[ "$FILTERON" == "" ]] && [[ "$DECON" == "" ]] && [[ "$INCON" == "" ]]; then      
        
                for comando in $(ps -Au $userfor -ofname,ni | tr -s " "); do
                    
                    if [[ "$COUNT" == 1 ]]; then
                        CMD=$comando
                    
                    elif [[ "$COUNT" == 2 ]]; then
                    
                        if [ $comando -ge "$ANICE" ] && [ $comando -le "$BNICE" ]; then
                            printf "$CMD\t$comando\n"
                        fi
                    fi
                done
############user, nice y filter                
            elif [[ "$NICEON" = 1 ]] && [[ "$FILTERON" == 1 ]] && [[ "$DECON" == "" ]] && [[ "$INCON" == "" ]]; then   
            
                for comando in $(ps -Au $userfor -ofname,ni | tr -s " "); do
                    
                    if [[ "$COUNT" == 1 ]]; then

                        if [ "$FILTER" == "$comando" ]; then
                            CMD=$comando
                        fi
                    
                    elif [[ "$COUNT" == 2 ]]; then
                    
                        if [ $comando -ge "$ANICE" ] && [ $comando -le "$BNICE" ]; then
                            if [ "$CMD" != "" ]; then
                                printf "$CMD\t$comando\n"
                            fi
                        fi
                    fi
                    CMD=
                done
############user y filter               
            elif [[ "$NICEON" = "" ]] && [[ "$FILTERON" == 1 ]] && [[ "$DECON" == "" ]] && [[ "$INCON" == "" ]]; then    
                
                for comando in $(ps -Au $userfor -ofname); do
                    
                    if [ "$FILTER" == "$comando" ]; then
                        printf "$comando"
                    fi
                done
############user e inc            
            elif [[ "$NICEON" = "" ]] && [[ "$FILTERON" == "" ]] && [[ "$DECON" == "" ]] && [[ "$INCON" == 1 ]]; then
                
                if renice -n $INC -u $userfor; then
                    echo "inc. con exito"
                
                else
                    error_exit "$LINENO: Ha ocurrido un error(inc)."
                fi
############user y dec            
            elif [[ "$NICEON" = "" ]] && [[ "$FILTERON" == "" ]] && [[ "$DECON" == 1 ]] && [[ "$INCON" == "" ]]; then         
            
                if renice -n $INC -u $userfor; then
                    echo "Dec. con exito"
                
                else
                    error_exit "$LINENO: Ha ocurrido un error(dec)."
                fi
############user                
            elif [[ "$NICEON" = "" ]] && [[ "$FILTERON" == "" ]] && [[ "$DECON" == "" ]] && [[ "$INCON" == "" ]]; then
                echo "$(ps -Au $userfor --no-headers)"
            fi
        done
####COMIENZO FILTER        
    elif [[ "$FILTERON" == 1 ]]; then
########filter e inc
        if [[ "$INC" == 1 ]]; then
            
            for comando in $(ps -A -opid,fname); do
                
                if [ "$FILTER" == "$comando" ] && [[ "$COUNT" == 1 ]]; then
                    CMD=$comando
                
                elif [[ "$COUNT" == 2 ]] && [ "$CMD" != "" ]; then
   
                    if renice -n $INC -p $CMD; then
                        echo "Exito en el comando con pid = $CMD"
                        CMD=
                        COUNT=0
                    
                    else
                        error_exit "$LINENO: Ha ocurrido un error(filter, inc)."
                    fi
                fi
                COUNT=$((COUNT + 1))
                
                if [[ "$COUNT" == 3 ]]; then
                    COUNT=1
                fi
            done
########filter e dec
        elif [[ "$DEC" == 1 ]]; then
            
            for comando in $(ps -A -opid,fname); do
                
                if [ "$FILTER" == "$comando" ] && [[ "$COUNT" == 1 ]]; then
                    CMD=$comando
                
                elif [[ "$COUNT" == 2 ]] && [ "$CMD" != "" ]; then
   
                    if renice -n $DEC -p $CMD; then
                        echo "Exito en el comando con pid = $CMD"
                        CMD=
                        COUNT=0
                        
                    else
                        error_exit "$LINENO: Ha ocurrido un error(filter, inc)."
                    fi
                fi
                COUNT=$((COUNT + 1))
                
                if [[ "$COUNT" == 3 ]]; then
                    COUNT=1
                fi
            done
########filter        
        else
        
            for comando in $(ps -A -ofname); do
                    
                if [ "$FILTER" == "$comando" ]; then
                    printf "Encontre: $comando\n"
                fi
            done
        fi
    fi
}




#PROGRAMA PRINCIPAL

if [ "$1" = "" ]; then
    COUNT=1
    (sin_opcion)
fi

if [ "$1" != "" ]; then
  ON=1
fi

while [ "$1" != "" ]; do

    case $1 in

        -u | --user   )
                shift
                USERON=1
                VARUSER=$(echo $1 | cut -c1)
                
                while [ "$VARUSER" != "-" ] && [ "$VARUSER" != "" ]; do
                    echo "$1"
                    echo "$1" >> $FLAG_USER
                    shift
                    VARUSER=$(echo $1 | cut -c1)
                done
                continue
                ;;

        -n | --nice   )
                shift
                NICEON=1
                ANICE=$(echo $1)
                shift
                BNICE=$(echo $1)
                ;;

        -i | --inc    )
                shift
                INCON=1
                INC=$1
                ;;

        -d | --dec    )
                shift
                DECON=1
                DEC=$1
                ;;

        -f | --filter )
                shift
                FILTERON=1
                FILTER=$(echo $1)
                ;;

        * )
                echo "opcion invalida"
                exit 1
    esac
    shift
done

if [ "$ON" ]; then
  (principal)
fi
