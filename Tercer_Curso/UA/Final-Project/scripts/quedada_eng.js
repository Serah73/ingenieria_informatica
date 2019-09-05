var rootRef2 = firebase.database().ref().child("Meetings");

rootRef2.on("child_added", snap => {

    var quedada = snap.child("Meeting").val();
    console.log(quedada);
    var cuenta = snap.child("User").val();
    console.log(cuenta);
    var libro = snap.child("Book").val();
    console.log(libro);
    var lugar = snap.child("Place").val();
    console.log(lugar);
    var hora = snap.child("Hour").val();
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
    var ejemlib = firebase.database().ref().child("Books");

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
                $('#assembly-mail').text("The email must have the following format: mail@mail.com. The email must match the email in the current account.").css('color', 'red');
                a = false;
            }


        });


        ejemlib.on("child_added", snap => {

            var titulo = snap.child("Title").val();
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
            $('#assembly-hour').text("Enter a valid hour (8:00-20:00).").css('color', 'red');
            tim = false;
        }



        if (date()) {
            $('#assembly-date').removeClass('invalid');
            $('#assembly-date').html('&#10004;').css('color', 'green');
            dat = true;
        } else {
            $('#assembly-date').addClass('invalid');
            $('#assembly-date').text("Enter a valid date. The date should be greater than the current date.").css('color', 'red');
            dat = false;
        }




        if ($('#lugar').val() != "") {
            $('#assembly-place').removeClass('invalid');
            $('#assembly-place').html('&#10004;').css('color', 'green');
            b = true;
        } else {
            $('#assembly-place').addClass('invalid');
            $('#assembly-place').text("Location not entered. Example: Las Americas, telepizza, ...").css('color', 'red');
            b = false;
        }


        if ($('#ciudad').val() != "") {
            $('#assembly-city').removeClass('invalid');
            $('#assembly-city').html('&#10004;').css('color', 'green');
            c = true;
        } else {
            $('#assembly-city').addClass('invalid');
            $('#assembly-city').text("City not introduced. Example:Madrid, Arrecife...").css('color', 'red');
            c = false;
        }


        if ($('#calle').val() != "") {
            $('#assembly-street').removeClass('invalid');
            $('#assembly-street').html('&#10004;').css('color', 'green');
            d = true;
        } else {
            $('#assembly-street').addClass('invalid');
            $('#assembly-street').text("Street not introduced. Example: Oxford, Verdellano,...").css('color', 'red');
            d = false;
        }
        if ($('#edificio').val() != "") {
            $('#assembly-building').removeClass('invalid');
            $('#assembly-building').html('&#10004;').css('color', 'green');
            e = true;
        } else {
            $('#assembly-building').addClass('invalid');
            $('#assembly-building').text("Building not introduced. Example: Altemar, ESIT...").css('color', 'red');
            e = false;
        }
   
        if ($('#puerta').val() != "") {
            $('#assembly-door').removeClass('invalid');
            $('#assembly-door').html('&#10004;').css('color', 'green');
            f = true;
        } else {
            $('#assembly-door').addClass('invalid');
            $('#assembly-door').text("Door not introduced. Example: 4ºA.").css('color', 'red');
            f = false;
        }

        if ($('#field1').val() != "" && check == true) {
            $('#assembly-book').removeClass('invalid');
            $('#assembly-book').html('&#10004;').css('color', 'green');
            book = true;
        } else {
            $('#assembly-book').addClass('invalid');
            $('#assembly-book').text("Enter a valid book name. Example: Harry Potter and the Philosopher's Stone.... ").css('color', 'red');
            book = false;
        }



    }
    else {
        $('#incorrecto').addClass('invalid');
        $('#incorrecto').text("ERROR. You must be loged in to create a meeting.").css('color', 'red');
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
                let referencia = database.ref('Meetings/' + VQuedada);

                referencia.set({

                    User: VCorreo,
                    Meeting: VQuedada,
                    Hour: VHora,
                    Place: VLugar,
                    Book: VLibro

                });
                console.log("entre")

            } else {
                console.log("NO logueado");
            }
        });
    }
    document.getElementById("operacion").style.display = "block";
    
};