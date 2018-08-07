
#!/bin/bash

# sysinfo_page - Un script que produce un archivo HTML
##### Constantes
TITLE="Información del sistema para $HOSTNAME"
RIGHT_NOW=$(date +"%x %r %Z")
TIME_STAMP="Actualizada el $RIGHT_NOW por $USER"
filename=sysinfo_page.html
fun=
interactive=0
filtro=
PROGNAME=$(basename $0)                 #La órden "basename" se utiliza para extraer los directorios de una ruta especificada 
                                        #como argumento y despliega en pantalla solamente el último componente de este camino
ESPACIOO=
NARCH=
NSUBDIR=
##### Funciones
system_info()
{
   echo "<h2>Información de versión del sistema</h2>"
   echo "<p>Función no implementada</p>"
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
    if [ "$1" = "" ]; then
        echo "<h2>Utilización de espacio de disco</h2>" 
        echo "<pre>"
        df
        echo "</pre>"
    else
        echo "<h2>Utilización de espacio de disco con filtro $1 </h2>"
        echo "<pre>"
        df | grep $1
        echo "</pre>"
    fi
}


open_files()
{
    echo "<h2> Usuarios con algun archivo abierto"
    echo "<pre>"
    echo "| User  |  Nºarchivos|"
    for i in $( cat /etc/passwd | cut -f1 -d\: ); do
        echo "| $i  |   $(lsof -u $i | wc -l)|"
    done
    echo "</pre>"
}


home_space()        #du muestra la capacidad de un archivo
{  
  if [ $USER = root ]; then                     # HAY QUE PROCESAR LOS DIRECTORIOS
    ESPACIOO=$(du -s /home)         #//////1---ESPACIO(du)///2---Nº archivos(dir+subdir)///3---Nº subdir
    NARCH=$(find -type f | wc -l)               # encuentra todos los archivos("-type f") cuenta todas las lineas ("wc -l")
    cd /home                                    # tenemos que entrar en home porque sino el find de dir buscara desde la carpeta actual
    NSUBDIR=$(find -type d | wc -l)             # idem(^2) dir("-type d")
    printf "espacio %s\n Nºarchivos %d\n Nºdirectorios %d" "$ESPACIOO" "$NARCH" "$NSUBDIR"
  else
    ESPACIOO=$(du -s /home/$USER)              # HAY QUE PROCESAR "$USER"
    NARCH=$(find -type f | wc -l)
    cd /home
    NSUBDIR=$(find $(pwd) -type d | wc -l)
    printf "espacio %s\n Nºarchivos %d\n Nºdirectorios %d" "$ESPACIOO" "$NARCH" "$NSUBDIR"
  fi
}

##### FUNCION PRACTICA DOS
usage()
{
   echo "usage: sysinfo_page [[[-f file ] [-i] [-p filter] | [-h]]"
}

redireccion()
{
cat << _EOF_
<html>
<head>
 <title>
 $TITLE
 </title>
</head>

<body>
 <h1>$TITLE</h1>
  <p>$TIME_STAMP</p>
 $(system_info)
 $(show_uptime)
 $(drive_space $filtro)
 $(home_space)
 $(open_files)
</body>
</html>
_EOF_
}


modo_interactivo()
{
        echo "introduzca el nombre del fich"
        read filename
       # $(cd ~/)
        if [ -f $filename ]; then  #            -               -               #comprueba si existe
            echo "Sí, existe.¿Desea sobreescribir y/n?"
            read fun   #y/n
            case $fun in
                y )  echo "el archivo se ha sobreescrito"
                     redireccion>$filename
                     exit
                     ;;
                n )  exit
                     ;;
                * )  echo "opcion no valida"
                     exit 1
                     ;;
            esac
        else              #               -                  -                  # caso no existe
            echo "No, exíste el archivo"
            redireccion>$filename
            echo "El archivo se ha creado"
        fi
}

error_exit()
{
    echo "${PROGNAME}: ${1:-"Error desconocido"}" 1>&2
    exit 1
    #El uso de ${PROGNAME}  significa poner la variable pero al estar entre llaves hace que al hacer "echo" aparezca separado del resto del texto
    #                           ----------NOTA: BUENA COSTUMBRE SIEMPRE PONERLO ENTRE LLAVES "{","}"---------------
    #El uso de ${1:-"Error desconocido"} significa que si el parámetro 1 ($1) no está definido,
    #se sustituye por la cadena "Error desconocido"
}

##### P R O G R A M A      P R I N C I P A L
for i in df du uptime; do
    if ! [ $(which $i) ]; then
        error_exit "falta un programa básico para el funcionamiento del script"
    fi
done


while [ "$1" != "" ]; do
   case $1 in
       -f | --file )                shift
                                    filename=$1
                                    ;;
       -i | --interactive )         interactive=1
                                    ;;
       -h | --help )                usage
                                    exit
                                    ;;
       -p | --partitions-filter )   shift
                                    filtro=$1
                                    ;;
       * )                          usage
                                    error_exit "Opción no permitida"
   esac
   shift
done

if [ $interactive -eq 1 ]; then
    modo_interactivo
else 
    "redireccion">$filename
fi


# si un comando tiene exito devuelve 0, si tiene un error devuelve otro nº, lo devuelve en la variable "$?"
#     1>&2 significa sacar 1 por la salida de errores en vez de la estandar
#  sacar el proceso "X"   por ">" la salida "&"  "Y"