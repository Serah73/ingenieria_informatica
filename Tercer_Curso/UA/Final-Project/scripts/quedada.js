var rootRef2 = firebase.database().ref().child("Quedadas");

rootRef2.on("child_added", snap => {

    var quedada = snap.child("Quedada").val();
    console.log(quedada);
    var cuenta = snap.child("Cuenta").val();
    console.log(cuenta);
    var libro = snap.child("Libro").val();
    console.log(libro);
    var lugar = snap.child("Lugar").val();
    console.log(lugar);
    var hora = snap.child("Hora").val();
    console.log(hora);

    var x = window.matchMedia("(max-width: 768px)");

    if (x.matches) { // If media query matches;
        $("#table_body2").append("<tr><td>" + quedada + "</td><td>" + libro + "</td><td>" + lugar + "</td><td>" + hora + "</td></tr>");
    } else {
        $("#table_body2").append("<tr><td>" + quedada + "</td><td>" + cuenta + "</td><td>" + libro + "</td><td>" + lugar + "</td><td>" + hora + "</td></tr>");
    }
});




function date() {
    var date = document.getElementById('fecha_quedada').value;
    if (new Date() < new Date(date)) {
        return true;
    }
    return false;
}


function time() {
    var tim = document.getElementById("hora");
    var setVal = tim.defaultValue;
    var inputVal = tim.value;

    if (setVal <= inputVal && inputVal <= "20:00:00") {
        return true;
    }

    return false;
}


function CheckCampo() {


    var a, b, c, d, e, f, dat, tim, book;
    var check = false;
    var ejemlib = firebase.database().ref().child("Libros");

    const regex = /^([a-zA-Z0-9.-])+@(([a-zA-Z0-9-])+.)+([a-zA-Z0-9]{2,4})+$/;

    var user = firebase.auth().currentUser;
    if (user != null) {
        user.providerData.forEach(function (profile) {

            var VCorreo = $('#correo').val();


            if ((regex.test($('#correo').val())) && (profile.email === VCorreo)) {
                $('#assembly-mail').removeClass('invalid');
                $('#assembly-mail').html('&#10004;').css('color', 'green');
                a = true;
                console.log("correcto");
            } else {
                $('#assembly-mail').addClass('invalid');
                $('#assembly-mail').text("El correo debe tener el siguiente formato: mail@mail.com. El correo debe ser igual al correo de la cuenta actual.").css('color', 'red');
                a = false;
            }


        });


        ejemlib.on("child_added", snap => {

            var titulo = snap.child("Título").val();
            console.log(titulo);

            var Vtitulo2 = $('#field1').val();
            console.log(Vtitulo2);

            if (Vtitulo2 == titulo) {
                check = true;
            }

        });



        if (time()) {
            $('#assembly-hour').removeClass('invalid');
            $('#assembly-hour').html('&#10004;').css('color', 'green');
            tim = true;
        } else {
            $('#assembly-hour').addClass('invalid');
            $('#assembly-hour').text("Introduzca una hora válida (8:00-20:00).").css('color', 'red');
            tim = false;
        }



        if (date()) {
            $('#assembly-date').removeClass('invalid');
            $('#assembly-date').html('&#10004;').css('color', 'green');
            dat = true;
        } else {
            $('#assembly-date').addClass('invalid');
            $('#assembly-date').text("Introduzca una fecha válida. La fecha debería ser mayor que la fecha actual.").css('color', 'red');
            dat = false;
        }




        if ($('#lugar').val() != "") {
            $('#assembly-place').removeClass('invalid');
            $('#assembly-place').html('&#10004;').css('color', 'green');
            b = true;
        } else {
            $('#assembly-place').addClass('invalid');
            $('#assembly-place').text("Lugar no introducido. Ejemplo: Las Americas, telepizza,...").css('color', 'red');
            b = false;
        }


        if ($('#ciudad').val() != "") {
            $('#assembly-city').removeClass('invalid');
            $('#assembly-city').html('&#10004;').css('color', 'green');
            c = true;
        } else {
            $('#assembly-city').addClass('invalid');
            $('#assembly-city').text("Ciudad no introducida. Ejemplo: Madrid, Arrecife...").css('color', 'red');
            c = false;
        }


        if ($('#calle').val() != "") {
            $('#assembly-street').removeClass('invalid');
            $('#assembly-street').html('&#10004;').css('color', 'green');
            d = true;
        } else {
            $('#assembly-street').addClass('invalid');
            $('#assembly-street').text("Calle no introducido. Ejemplo: Oxford, Verdellano,...").css('color', 'red');
            d = false;
        }
        if ($('#edificio').val() != "") {
            $('#assembly-building').removeClass('invalid');
            $('#assembly-building').html('&#10004;').css('color', 'green');
            e = true;
        } else {
            $('#assembly-building').addClass('invalid');
            $('#assembly-building').text("Edificio no introducido. Ejemplo: Altemar, ESIT...").css('color', 'red');
            e = false;
        }
   
        if ($('#puerta').val() != "") {
            $('#assembly-door').removeClass('invalid');
            $('#assembly-door').html('&#10004;').css('color', 'green');
            f = true;
        } else {
            $('#assembly-door').addClass('invalid');
            $('#assembly-door').text("Puerta no introducida. Ejemplo: 4ºA.").css('color', 'red');
            f = false;
        }

        if ($('#field1').val() != "" && check == true) {
            $('#assembly-book').removeClass('invalid');
            $('#assembly-book').html('&#10004;').css('color', 'green');
            book = true;
        } else {
            $('#assembly-book').addClass('invalid');
            $('#assembly-book').text("Introduce un nombre de libro válido. Ejemplo: El principito, La cabaña... ").css('color', 'red');
            book = false;
        }



    }
    else {
        $('#incorrecto').addClass('invalid');
        $('#incorrecto').text("ERROR. Debe loguearse para registrar una quedada.").css('color', 'red');
    }

    if (a == true && b == true && c == true && d == true && e == true && f == true && dat == true && book == true && tim == true){
        document.getElementById('send').style.display = 'block';
        console.log("El boton");
 
    }else{
        document.getElementById('send').style.display = 'none';
    }

}


function pushData() {
    var user = firebase.auth().currentUser;
    if (user != null) {
        user.providerData.forEach(function (profile) {
            var VCorreo = $('#correo').val();
            if (profile.email == VCorreo) {
                console.log("logueado");

                const VQuedada = $('#fecha_quedada').val();;
                const VHora = $('#hora').val();
                const VLibro = $('#field1').val();
                const VLugar = $('#lugar').val();



                let database = firebase.database();
                let referencia = database.ref('Quedadas/' + VQuedada);

                referencia.set({

                    Cuenta: VCorreo,
                    Quedada: VQuedada,
                    Hora: VHora,
                    Lugar: VLugar,
                    Libro: VLibro

                });
                console.log("entre")

            } else {
                console.log("NO logueado");
            }
        });
    }
    document.getElementById("operacion").style.display = "block";
    
};