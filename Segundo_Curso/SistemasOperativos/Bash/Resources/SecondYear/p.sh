#!/bin/bash

fila=
var=

while [ $1 != "" ]; do
    
    case $1 in
    
        -f )
            fila=1
            shift
            ;;
        
        -u )
            shift
            var=$(echo $1 | cut -c1)
            
            while [ $var != "-" ]; do 
                $(ps --no-headers -u $1 >> pru.txt)
                shift    
            done
            ;;
    esac
done