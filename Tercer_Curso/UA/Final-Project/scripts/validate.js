function validar_email() {
    console.log("Validando");
    const regex = /^([a-zA-Z0-9.-])+@(([a-zA-Z0-9-])+.)+([a-zA-Z0-9]{2,4})+$/;

    if (regex.test($('#signup-email').val()) === true) {

        return true;
    } else {

        return false;
    }

}


function validar_contraseña() {
    console.log("CONTRASEÑAS");
    let p1 = $('#signup-password').val();

    // validate tamaño
    if (p1.length < 8) {
        $('#li_4').removeClass('valid').addClass('invalid');
        hidden = true;
    } else {
        $('#li_4').removeClass('invalid').addClass('valid');
    }

    // validate letra
    if (p1.match(/[A-z]/)) {
        $('#li_1').removeClass('invalid').addClass('valid');

    } else {
        $('#li_1').removeClass('valid').addClass('invalid');
        hidden = true;
    }

    // validate mayuscula letra
    if (p1.match(/[A-Z]/)) {
        $('#li_2').removeClass('invalid').addClass('valid');
    } else {
        $('#li_2').removeClass('valid').addClass('invalid');
        hidden = true;
    }

    //validate numero
    if (p1.match(/\d/)) {
        $('#li_3').removeClass('invalid').addClass('valid');
        hidden = true;
    } else {
        $('#li_3').removeClass('valid').addClass('invalid');
    }


}

function registerMail() {
    if (validar_email() === false) {

        $('#register-mail').addClass('invalid');
        $('#register-mail').text("Error mail invalido. Compruebe los datos. Ejemplo: mail@mail.com");
    } else {

        $('#register-mail').removeClass('invalid');
        $('#register-mail').text("");
    
    }
    validar_contraseña();
}

function loginReady() {

    let userLogin = firebase.auth().currentUser;
    const regex = /^([a-zA-Z0-9.-])+@(([a-zA-Z0-9-])+.)+([a-zA-Z0-9]{2,4})+$/;

    if (userLogin == null) {

        if (regex.test($('#login-email').val())) {    //compruebas el correo
            console.log("Correcto");
            $('#loginMail').removeClass('invalid');
            $('#loginMail').text("Introduzca su correo electrónico en el campo anterior.");
        } else {
            console.log("Incorrecto");
            $('#loginMail').addClass('invalid');
            $('#loginMail').text("Error mail invalido. Compruebe los datos. Ejemplo: mail@mail.com");
        }
    }
}

