#!/bin/bash

# sysinfo_page - Un script que produce un archivo HTML
##### Constantes
TITLE="Informacion del sistema para $HOSTNAME"
RIGHT_NOW=$(date +"%x %r %Z")
TIME_STAMP="Actualizada el $RIGHT_NOW por $USER"
SPACE="espacio que ocupan todos los usuarios: $(du -s /home)"
SPACE2="espacio que ocupa el usuario: $(du -s /home/$USER)"
CADENA="Espacio de subdirectorios:"

#p2
FILENAME=sysinfo_page.html
INTERACTIVE=
PROGNAME=$(basename $0)
H_READ=
FILTRO=
CUMPLE=false
TEMP=$(tempfile --prefix="tmp" --suffix=".miscript.$$")
TEMPD=$(tempfile --prefix="tmp" --suffix=".miscriptdos.$$")
TEMPT=$(tempfile --prefix="tmp" --suffix=".miscripttres.$$")

##### Funciones
system_info()
{
    # Función de stub temporal
   echo "función system_info"
   #echo "<pre>"

   #echo "</pre>"
}


show_uptime()
{
  echo "<h2>Tiempo de encendido del sistema</h2>"
  echo "<pre>"
  uptime
  echo "</pre>"
}


drive_space()
{
    # Función de stub temporal
    echo "<h2>Uso del espacio en disco</h2>"
    
    if [ "$1" = "" ]; then
        echo "<pre>"
        df
        echo "</pre>"
    
    else
        echo "<h2>Hemos detectado un FILTRO '$1'. Su espacio en disco es:"
        echo "<pre>"
        df | head -n1    #intento de mostrar la cabecera
        df | grep $1
        echo "</pre>"
    fi
}


home_space()
{
  if [ "$USER" = "root" ]; then
    
    echo "$SPACE"
    
    if [ "$1" = "" ]; then
        echo "<pre>$CADENA $(du -c --max-depth=1 /home |sort -n -r)</pre>" 
        
    else
        while [ "$1" = "" ]; do
            echo "<pre>$CADENA $(du -c --max-depth=1 $1 |sort -n -r)</pre>"
        done
    fi
    
  else  #si no es root
  
    if [ "$USER" != "$LOGNAME" ]; then
        echo "Usuarios distintos: $USER, $LOGNAME"
    fi
    
    echo "$SPACE2"
    echo "$CADENA <pre>$(du -c --max-depth=1 /home/$USER | sort -n -r)</pre>"
    echo "Procesos: $(ps --no-headers | wc -l)"
  fi
}

#---------------------------------p2


redireccion()
{
    cat << _EOF_
    <html>
    <head>
      <title>$TITLE</title>
    </head>
    
    <body>
      <h1>$TITLE</h1>
      <p>$TIME_STAMP</p>
      $(system_info)
      $(show_uptime)
      $(drive_space $FILTRO)
      $(home_space)
      $(proces)
    </body>
    </html>
_EOF_
}

modo_interactivo()
{
        echo "introduzca el nombre del fich"
        read FILENAME
        
        if [ -f $FILENAME ]; then
            echo "Sí, existe.¿Desea sobreescribir y/n?"
            read H_READ   #y/n
            
            while [ CUMPLE = false ]; do
                case $H_READ in
                    y ) redireccion>$FILENAME 
                        echo "el archivo se ha sobreescrito"
                        CUMPLE = true
                        exit
                        ;;
                    n ) echo "Saliendo.."
                        CUMPLE = true
                        exit
                        ;;
                    * ) echo "opcion no valida. Introduzca 'y' para Si y 'n' para No"
                        ;;
                esac
            done
        else
            echo "No exíste el archivo"
            redireccion>$FILENAME
            echo "El archivo se ha creado"
        fi
}


usage()
{
   echo "usage: sysinfo_page [[[-f file ] [-i]] | [-h]]"
}


proces()
{
  echo "<h2> Procesos activos de usuarios no logeados en el sistema </h2>"
  echo "<pre>"
  
  $(ps u -u > $TEMP)
  $(who | cut -f1 -d' ' | sort -f | uniq > $TEMPD )
  for linea in $(cat $TEMPD); do
    $(grep -v $linea $TEMP > $TEMPT)
    $(cat $TEMPT > $TEMPD)
  done
 
  echo "</pre>"
}


##### Programa principal

while [ "$1" != "" ]; do
   case $1 in
        
        -f | --file )       
                            shift
                            FILENAME=$1
                            ;;
        
        -i | --INTERACTIVE )
                            INTERACTIVE=1
                            ;;
        
        -h | --help )       
                            usage
                            exit
                            ;;
        
        -p | --partitions-filter )   
                            shift
                            FILTRO=$1
                            ;;
        * )                 
                            usage
                            exit 1
   esac
   shift
done

if [[ $INTERACTIVE -eq 1 ]]; then
    (modo_interactivo)
else 
    (redireccion)>$FILENAME
fi