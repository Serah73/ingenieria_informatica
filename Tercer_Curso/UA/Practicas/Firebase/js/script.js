




function comprobar(){
    if(mayor_edad() /*&& respuesta_email(mail) && validar_contraseña(pswd, pswd2)*/ === true) //poner aquí las restricciones
        document.getElementById('send').style.visibility = 'visible';
    else
        alert("Algun formato no esta relleno o tiene un formato incorrecto.");
}


function pushData() {
    

    console.log('hola');
    const VNombre = document.getElementById('nombre').value;
    console.log(VNombre);
    var VApellidos = document.getElementById('apellidos').value;
    console.log(VApellidos);
    var VUsuario = document.getElementById('usuario').value;
    console.log(VUsuario);
    const VPassword = document.getElementById('pswd').value;
    console.log(VPassword);
    const VNacimiento = document.getElementById('fecha_nacimiento').value;
    console.log(VNacimiento);
    const VPais = document.getElementById('pais').value;
    console.log(VPais);
    const VTelefono = document.getElementById('tlf').value;
    console.log(VTelefono);
    const VEmail = document.getElementById('mail').value;
    console.log(VEmail);
    

    let database = firebase.database();
    let referencia = database.ref('users/' + VUsuario);
    //Escribir un documento
    referencia.set({
        Nombre: VNombre,
        Apellidos: VApellidos,
        Usuario: VUsuario,
        Password: VPassword,
        Nacimiento: VNacimiento,
        Pais: VPais,
        Telefono: VTelefono,
        Correo: VEmail,
    });
    
   
};



function mayor_edad(){
    
    var datedate = document.getElementById('fecha_nacimiento').value;
    
    let fecha1 = new Date(datedate);
    let fecha2 = new Date();
    
    let resta = fecha2.getTime() - fecha1.getTime();
    // console.log(Math.round(resta/(1000*60*60*24)));
    if (Math.round(resta/(1000*60*60*24)) > 6570){
        // alert("Mayor de edad");
        return true;
    }else{
        return false;
        // alert("Lo siento, pero es menor de edad");
    }
    
}


function validar_email(mail) {
    const regex = /^([a-zA-Z0-9.-])+@(([a-zA-Z0-9-])+.)+([a-zA-Z0-9]{2,4})+$/;
    return regex.test(mail) ? true : false;
}


function respuesta_email(mail) {
    console.log("entro");
    if (this.validar_email(mail)) {
        return true;
        // alert('El email ' + email + ' es correcto');
    } else {
        return false;
        alert("El email no sigue el formato: correo@correo.correo");
    }
}

function validar_contraseña(pswd, pswd2) {
    console.log("Contraseñas");
    var p1 = document.getElementById("pswd").value;
    var p2 = document.getElementById("pswd2").value;
    var espacios = false;
    var cont = 0;


    while (!espacios && (cont < p1.length)) {
        if (p1.charAt(cont) == " ")
            espacios = true;
        cont++;
    }

    if (espacios) {
        alert("La contraseña no puede contener espacios en blanco");
        return false;
    }

    if (p1.length == 0 || p2.length == 0) {
        alert("Los campos de la contraseña no pueden quedar vacios");
        return false;
    }

    if (p1 != p2) {
        alert("Las contraseñas deben de coincidir");
        return false;
    } else {
        // alert("Todo esta correcto");
        return true;
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


   


