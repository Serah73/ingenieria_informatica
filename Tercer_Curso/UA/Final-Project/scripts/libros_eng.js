var rootRef = firebase.database().ref().child("Books");

rootRef.on("child_added", snap => {

    var titulo = snap.child("Title").val();
    console.log(titulo);
    var autor = snap.child("Author").val();
    console.log(autor);
    var año = snap.child("Year").val();
    console.log(año);
    var genero = snap.child("Genre").val();
    console.log(genero);
    var estrellitas = snap.child("Stars").val();
    console.log(estrellitas);
    var enlacito = snap.child("Link").val();
    console.log(enlacito);


    var x = window.matchMedia("(max-width: 768px)");

    if (x.matches) { // If media query matches;
        var sinopsis = "";
        $("#table_body").append("<tr><td>" + titulo + "</td><td>" + autor + "</td><td>" + genero + "</td><td>" + estrellitas + "</td></tr>");
    } else {
        var sinopsis = snap.child("Synopsis").val();
        $("#table_body").append("<tr><td tabindex='0'>" + titulo + "</td><td tabindex='0'>" + autor + "</td><td tabindex='0'>" + año + "</td><td tabindex='0'>" + genero + "</td><td tabindex='0'>" + sinopsis + "</td><td tabindex='0'>" + estrellitas + "</td><td tabindex='0'> <a href='" + enlacito + "'> <u> Link </u> </a> </td></tr>");
    }
});


function calificar(star) {
    var user = firebase.auth().currentUser;
    bool_titulo = false;
    bool_autor = false;
    bool_else = 1;
    var variable = 0;
    var variable_2 = 0;


    rootRef.on("child_added", snap => {

        var Vtitulo2 = $('#titulo_dato').val();
        var titulo = snap.child("Title").val();
        var autor_ = snap.child("Author").val();
        var Vautor2 = $('#autor_libro').val();



        if (user != null) {
            $('#necesita_loguearse').removeClass('invalid');
            $('#necesita_loguearse').text("");


            var rootRef = firebase.database().ref().child("Books");

            if ((titulo === Vtitulo2) && (Vautor2 === autor_)) {

                bool_else = 0;
                console.log("ACTUALIZO VARIABLE " + bool_else);

                $('#campo_titulo').removeClass('invalid').addClass('valid');
                hidden = true;
                console.log("CORRECTO TITULO en if ");


                $('#campo_autor').removeClass('invalid').addClass('valid');
                hidden = true;
                console.log("CORRECTO AUTOR en if");


                console.log("TODO CORRECTOOOO");

                var titulo = snap.child("Title").val();
                var autor = snap.child("Author").val();
                var año = snap.child("Year").val();
                var genero = snap.child("Genre").val();
                var sinopsis = snap.child("Synopsis").val();
                var estrellas = snap.child("Stars").val();
                var enlace = snap.child("Link").val();
                console.log(enlace);
                suma = estrellas + star;
                console.log(estrellas, " ", star, " ", suma);

                estrellas = suma;
                console.log(estrellas);

                // Actualizo la base de datos
                var Vtitulo = $('#titulo_dato').val();
                let database = firebase.database();
                let referencia = database.ref('Books/' + Vtitulo);
                console.log(referencia);
                referencia.set({

                    Title: titulo,
                    Author: autor,
                    Year: año,
                    Genre: genero,
                    Synopsis: sinopsis,
                    Stars: estrellas,
                    Link: enlace

                });
                $("#table_body").empty();
                $("#table_body").append("<tr><td>" + titulo + "</td><td>" + autor + "</td><td>" + año + "</td><td>" + genero + "</td><td>" + sinopsis + "</td><td>" + estrellas + "</td><td> <a href='" + enlace +  "'> <u> Link </u> </a> </td></tr>");
                                                                                                                                                          
                document.getElementById("operacion").style.display = "block";

            }


            if (bool_else === 1) {


                if ((titulo == Vtitulo2) && (Vautor2 == autor_)) {
                    console.log(" INSIDE titulo == Vtitulo2) && (Vautor2 == autor_)");
                    $('#campo_titulo').removeClass('invalid').addClass('valid');
                    hidden = true;
                    console.log("CORRECTO AUTOR");

                    $('#campo_autor').removeClass('invalid').addClass('valid');
                    hidden = true;
                    console.log("CORRECTO TITULO");
                    console.log("TODO CORRECTOOOO");
                     return false;


                }

                if ((titulo == Vtitulo2) && (Vautor2 != autor_) && (variable == 0)) {

                    console.log(" INSIDE (titulo == Vtitulo2) && (Vautor2 != autor_)");
                    variable_2 = 1;
                    $('#campo_titulo').removeClass('invalid').addClass('valid');
                    $('#campo_titulo').addClass('valid');
                    hidden = true;
                    console.log("CORRECTO TITULO");

                    $('#campo_autor').removeClass('valid').addClass('invalid');
                    $('#campo_autor').addClass('invalid');
                    console.log("INCORRECTO AUTOR");
                    return false;
                }






                if ((titulo != Vtitulo2) && (Vautor2 == autor_) && (variable == 0) && (variable_2 == 0)) {
                    variable = 1;

                    $('#campo_titulo').removeClass('valid').addClass('invalid');
                    console.log("INCORRECTO TITULO");

                    $('#campo_autor').removeClass('invalid').addClass('valid');
                    hidden = true;
                    console.log("CORRECTO AUTOR");

                    return false;

                }




                if ((titulo != Vtitulo2) && (Vautor2 != autor_) && (variable == 0) && (variable_2 == 0)) {
                    $('#campo_autor').removeClass('valid').addClass('invalid');
                    console.log("INCORRECTO AUTOR");
                    $('#campo_titulo').removeClass('valid').addClass('invalid');
                    console.log("INCORRECTO TITULO");
                    return false;
                }


                return false;

            }
            return false;





        } else {
            document.getElementById("incorrecto").style.display = "block";
            $('#incorrecto').addClass('invalid');
            $('#incorrecto').text("ERROR. You must log in to rank a book.");
        }
    });
}



