#!/bin/bash

TITLE="listado de usuarios"
TEMP_FILE_US=$(tempfile --prefix="tmp" --suffix=".miscript.$$")                  #duda al crear el fich, ¿cuando se borra o como borrarlo?
TEMP_FILE_N=$(tempfile --prefix="tmp" --suffix=".miscriptun.$$")
error_exit()
{
   echo "${PROGNAME}: ${1:-"Error desconocido"}" 1>&2
   exit 1
}

listado()
{
   echo "<pre>"
   echo "$(ps -A -ouser | sort -f | uniq)"                                       #sort -f es ordenar alfabeticamente
   echo "</pre>"
}

grupo()
{
   echo "<pre>"
   $(more /etc/passwd | cut -f1 -d\: > $TEMP_FILE_US)
   for linea in $( cat $TEMP_FILE_US ); do                                       # recorrer cada linea del fichero temporal
      identidad=$(id -u $linea)                                                  # id es para sacar el numero UID
   	if [ $identidad = 0 ];then	
   	   echo " Reservado para root"
	   elif [ $identidad -gt 0 ] && [ $identidad -lt 100 ];then
	      echo "$linea reservado predifinido"
	   elif [ $identidad -gt 100 ] &&  [ $identidad -lt 999 ];then
	      echo "$linea administrador"
	   elif [ $identidad -ge 1000 ];then
	      echo "$linea convencional"
      fi
   done
   echo "</pre>"
}

arranque()
{
      valido=$(which $1)
      if [ "$valido" != "/bin/false" ]; then
         val="arranque valido"
      else
         error_exit "el usuario no tiene arranque valido"
      fi
}

global()
{
   if [ "$1" = "-u" ]; then
   shift
      while [ "$1" != "" ];do
      arranque $1
         identidad=$(id -u $1)                                                  
         if [ $identidad = 0 ];then	
            echo " Reservado para root $val"
         elif [ $identidad -gt 0 ] && [ $identidad -lt 100 ];then
            echo "$1 reservado predifinido $val"
         elif [ $identidad -gt 100 ] &&  [ $identidad -lt 999 ];then
            echo "$1 administrador $val"
         elif [ $identidad -ge 1000 ];then
            echo "$1 convencional $val"
         fi
         shift
      done
   elif [ "$1" = "-n" ]; then
   shift
    $(cat /etc/passwd | cut -f1 -d\: > $TEMP_FILE_US)
      while [ "$1" != "" ];do                                                    #quitamos los usuarios 
         $(grep -v $1 $TEMP_FILE_US > $TEMP_FILE_N)         # A Q U I    E S T A B A   E L    P R O B L E M A    D E   -N
         $(cat $TEMP_FILE_N > $TEMP_FILE_US)
         shift
      done
      
      for linea in $( cat $TEMP_FILE_N ); do                                     #recorremos el fich para mostrar todos los user que no hemos quitado
         arranque $1
         identidad=$(id -u $linea)
         if [ $identidad = 0 ];then	
            echo " Reservado para root $val"
         elif [ $identidad -gt 0 ] && [ $identidad -lt 100 ];then
            echo "$linea reservado predifinido $val"
         elif [ $identidad -gt 100 ] &&  [ $identidad -lt 999 ];then
            echo "$linea administrador $val"
         elif [ $identidad -ge 1000 ];then
            echo "$linea convencional $val"
         fi
      done
   fi
}

#PROGRAMA PRINCIPAL
for i in id ps more sort uniq; do
    if ! [ $(which $i) ]; then
        error_exit "falta un programa básico para el funcionamiento del script"
    fi
done


if [ "$1" = "" ]; then
   arranque
   echo "lista de usuarios con algun proceso abierto"
   listado
   echo "grupos"
   grupo
else
   #while [ "$1" != "" ]; do
      case $1 in
         -u | --users )    global $@
                           shift
                           ;;
         -n | --nousers )  global $@
                           shift
                           ;;
         *  )              usage
                           error_exit "Opción no permitida"
      esac
   #   shift
   #done
fi