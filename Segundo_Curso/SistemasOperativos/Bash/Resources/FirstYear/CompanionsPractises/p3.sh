#!/bin/bash 

# sysinfo_page - Un script que produce un archivo HTML
##### Constantes
TITLE="Información del sistema para $HOSTNAME"
RIGHT_NOW=$(date +"%x %r %Z")
TIME_STAMP="Actualizada el $RIGHT_NOW por $USER"
filename=~/sysinfo_page.html
fun=
interactive=
filtro=
PROGNAME=$(basename $0)
Direccion=
usuario="$USER"
numero=" "
variable=" "
dir=" "
file=" "
rute=" "
cap=" "
##### Funciones
system_info()
{
   echo "<h2>Información de versión del sistema</h2>"
   echo "<pre>"	
   uname -a						#funcion que muestra la informacion del sistema
   echo "</pre>"
}

show_uptime()
{
   echo "<h2>Tiempo de encendido del sistema</h2>"							#funcion que muestra el tiempo de encendido del sistema 	
   echo "<pre>"
   uptime																					
   echo "</pre>"
}


drive_space()											       #funcion que muestra el espacio total del disco 
{  
    if [ "$1" = "" ]; then
        echo "<h2>Utilización de espaciode disco</h2>" 							
        echo "<pre>"											#en este caso no hay argumentos de función (el modo interactivo = 0)
        df										                #comando df
        echo "</pre>"
    else
        echo "<h2>Utilización de espacio de disco con filtro $1 </h2>"
        #echo "S.ficheros     bloques de 1K  Usados Disponibles Uso% Montado en"			#se muestra un menu que sera puesto en el HTML con el filtro que le haya pasado el usuario.
        echo "<pre>"											#df | grep $1
        df | grep $1
        echo "</pre>"
    fi
}
open_files()
{
echo "<h2>Lista de usuarios abriendo cosas</h2>"							#funciona con un bucle para que lo haga con todos los usuarios
echo "<pre>"
 
   	cd /home
	printf "Usuario  Numero de archivos \n"								#primero va a la carpeta /home que es donde se localizan las carpetas de todos los usuarios	
 	ls | while read variable; do									#hace un ls y lo que salga de ahi lo va guardando en numero
 	numero=$(lsof -u $variable | wc -l)
	echo "$variable   $numero"
													#impresion de los datos



													#fin del bucle
	done



echo "</pre>"

}

home_space()        												#du muestra la capacidad de un archivo
{           
	echo "<h2>Número de archivos abiertos</h2>"								#funciona con un bucle para que lo haga con todos los usuarios
	echo "<pre>"                            								#funciona falta la impresión.
 if [ $USER = root ]; then
    cd /home
    rute=$(find /home -maxdepth 0)                									#ruta del directorio pero hay que ir antes.
    file=$(find -type f| wc -l)                  									#cuenta el numero de archivos de donde este el find
    dir=$(find -type d | wc -l)                  									#cuenta el numero de directorios de donde estes pero hay que ir antes
    cap=$(du -s /home/*)
	printf " Directorios Archivos         Usado  Directorio\n"
	printf "  %d         %d        %s     %s" "$dir" "$file" "$cap" "$rute"
  else  
    cd /home/$USER
    rute=$(find /home/$USER -maxdepth 0)                								#ruta del directorio pero hay que ir antes.
    file=$(find -type f| wc -l)                   									#cuenta el numero de archivos de donde este el find
    dir=$(find -type d | wc -l)                  									#cuenta el numero de directorios de donde estes pero hay que ir antes
    cap=$(du -s /home/$USER)
	printf " Directorios Archivos         Usado  Directorio\n"
	printf "  %d         %d        %s     %s" "$dir" "$file" "$cap" "$rute"
	fi
	echo "</pre>"
}
error_exit()
{	
		if [ $1 = "" ]; then
        echo "${PROGNAME}: ${1:-"Error desconocido"}" 1>&2
		else
		echo "el error está en $1"
		fi
        exit 1
}

##### FUNCION PRACTICA DOS
usage()
{	
   echo "usage: sysinfo_page [[[-f file ] [-i] [-p filter] | [-h]]"	#esta funcion salta junto a la funcion error_exit si se ha metido un parámetro incorrecto al principio				 #
   
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
            read fun   #y/n							#si existe pregunta para crear un nuevo archivo si se le pone y se sobreescibre n no
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

##### P R O G R A M A      P R I N C I P A L

  Direccion=$(which du) 

  if [ -f $Direccion ] ; then
    echo " "
  else 
	
    error_exit -$Direccion
  fi
  
  Direccion=$(which df) 
  								#Primera comprobación de errores, se mira si los programas están instalados
  if [ -f $Direccion ] ; then					#en el sistema en este caso vamos a usar du, df , uptime ,lsof ,wc
    echo " "
  else 
    error_exit -$Direccion
  fi
  
  Direccion=$(which uptime) 
  
  if [ -f $Direccion ] ; then           
    echo " "
  else 
    error_exit -$Direccion
  fi

 Direccion=$(which lsof) 
  
  if [ -f $Direccion ] ; then           
    echo " "
  else 
    error_exit -$Direccion
  fi

 Direccion=$(which wc) 
  
  if [ -f $Direccion ] ; then           
    echo " "
  else 
    error_exit -$Direccion
  fi






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
                                    error_exit
                                    exit 1
   esac
   shift
done


if [ $interactive -eq 1 ]; then
    (modo_interactivo)
else 
    "redireccion">$filename
fi
