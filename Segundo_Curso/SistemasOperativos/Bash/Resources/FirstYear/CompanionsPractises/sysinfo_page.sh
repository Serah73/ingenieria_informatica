
#!/bin/bash -x

# sysinfo_page - Un script que produce un archivo HTML
##### Constantes
TITLE="Información del sistema para $HOSTNAME"
RIGHT_NOW=$(date +"%x %r %Z")
TIME_STAMP="Actualizada el $RIGHT_NOW por $USER"
filename=sysinfo_page.html
fun=
interactive=
filtro=
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
        echo "<h2>Utilización de espaciode disco</h2>" 
        echo "<pre>"
        df
        echo "</pre>"
    else
        echo "<h2>Utilización de espacio de disco con filtro $1 </h2>"
        #echo "S.ficheros     bloques de 1K  Usados Disponibles Uso% Montado en"
        echo "<pre>"
        df | grep $1
        echo "</pre>"
    fi
}


home_space()        #du muestra la capacidad de un archivo
{  
  if [ $USER = root ]; then
    #$(cd /home)
    du -s /home/*
  else
    #$(cd /home/$USER)
    du -s /home/$USER
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
 $(who_rou)
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

who_rou()
{
	echo "¿nº que se repite el user?"
	echo "<pre>"
	who | cut -f1 -d' ' | wc -w
	echo "</pre>"
	echo "todos los user"
	echo "<pre2>"
	who | cut -f1 -d' ' | sort | uniq -d
	echo "</pre2>"
}

##### P R O G R A M A      P R I N C I P A L

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
      # -w | --who-user )	    shift
       * )                          usage
                                    exit 1
   esac
   shift
done

if [[ $interactive -eq 1 ]]; then
    (modo_interactivo)
else 
    "redireccion">$filename
fi
