function comprobar(){
    
   
    if(respuesta_email($('#mail').val() )) 
    {
        $('#check_mail').removeClass('invalid').addClass('valid');
        $('#check_mail').text("Formato Correcto");
    }
    else{
        $('#check_mail').removeClass('valid').addClass('invalid');
        $('#check_mail').text("Formato incorrecto");
    }
    
    if(validar_contraseña() == 0)
    {
        $('#check_psw1').removeClass('invalid').addClass('valid');
        $('#check_psw1').text("Correcto");
    }
    else if (validar_contraseña() == -1)
    {
        $('#check_psw1').removeClass('valid').addClass('invalid');
        $('#check_psw1').text("Hay espacios en la contraseña");
    }
    else if(validar_contraseña() == -2 )
    {
        $('#check_psw1').removeClass('valid').addClass('invalid');
        $('#check_psw1').text("EL campo de contraseña es obligatorio");
    }
        
    

    if((respuesta_email($('#mail').val()) &&  (validar_contraseña())) === true) //poner aquí las restricciones
        document.getElementById('send').style.visibility = 'visible';
}



function validar_email() {
    const regex = /^([a-zA-Z0-9.-])+@(([a-zA-Z0-9-])+.)+([a-zA-Z0-9]{2,4})+$/;
    return regex.test($('#mail').val()) ? true : false;
}


function respuesta_email() {
    
    if (this.validar_email($('#mail').val())) {
        return true;
        // alert('El email ' + email + ' es correcto');
    } else {
        return false;
        //alert("El email no sigue el formato: correo@correo.correo");
    }
}

function validar_contraseña() {
    let p1= $('#pswd').val();
    let p2 = $('#pswd2').val();
 
    let espacios = false;
    let cont = 0;


    while (!espacios && (cont < p1.length)) {
        if (p1.charAt(cont) == " ")
            espacios = true;
        cont++;
    }

    if (espacios) {
        //alert("La contraseña no puede contener espacios en blanco");
        return -1;
    }
    if (p1.length == 0 || p2.length == 0) {
        //alert("Los campos de la contraseña no pueden quedar vacios");
        return -2;
    }

    if (p1 != p2) {
        //alert("Las contraseñas deben de coincidir");
        return -3;
    } else {
        // alert("Todo esta correcto");
        return 0;
    }

}


$(document).ready(function () {

    $('input[type=password]').focusout(function () {
        $('#pswd_info').show();
        
        let pswd = $("#pswd")[0].value
        
       //validate the length
        if (pswd.length < 8) {
            $('#length').removeClass('valid').addClass('invalid');
            hidden = true;
        } else {
            $('#length').removeClass('invalid').addClass('valid');
        }

        // validate letra
        if (pswd.match(/[A-z]/)) {
            $('#letra').removeClass('invalid').addClass('valid');
            
        } else {
            $('#letra').removeClass('valid').addClass('invalid');
            hidden = true;
        }

        // validate mayuscula letra
        if (pswd.match(/[A-Z]/)) {
            $('#mayuscula').removeClass('invalid').addClass('valid');
        } else {
            $('#mayuscula').removeClass('valid').addClass('invalid');
            hidden = true;
        }

        //validate numero
        if (pswd.match(/\d/)) {
            $('#numero').removeClass('invalid').addClass('valid');
            hidden = true;
        } else {
            $('#numero').removeClass('valid').addClass('invalid');
        }
    });
    
   
});


