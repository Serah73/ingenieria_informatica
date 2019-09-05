var rootRef = firebase.database().ref().child("Libros");

rootRef.on("child_added", snap => {

    var titulo = snap.child("Título").val();
    console.log(titulo);
    var autor = snap.child("Autor").val();
    console.log(autor);
    var año = snap.child("Año").val();
    console.log(año);
    var genero = snap.child("Género").val();
    console.log(genero);
    var estrellitas = snap.child("Estrellas").val();
    console.log(estrellitas);
    var enlacito = snap.child("Enlace").val();
    console.log(enlacito);


    var x = window.matchMedia("(max-width: 768px)");

    if (x.matches) { // If media query matches;
        var sinopsis = "";
        $("#table_body").append("<tr><td> " + titulo + "</td><td>" + autor + "</td><td>" + genero + "</td><td>" + estrellitas + "</td></tr>");
    } else {
        var sinopsis = snap.child("Sinopsis").val();
        $("#table_body").append("<tr><td tabindex='0'>" + titulo + "</td><td tabindex='0'>" + autor + "</td><td tabindex='0'>" + año + "</td><td tabindex='0'>" + genero + "</td><td tabindex='0'>" + sinopsis + "</td><td tabindex='0'>" + estrellitas + "</td><td> <a href='" + enlacito + "'> <u> Enlace </u> </a> </td></tr>");
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
        var titulo = snap.child("Título").val();
        var autor_ = snap.child("Autor").val();
        var Vautor2 = $('#autor_libro').val();



        if (user != null) {
            $('#necesita_loguearse').removeClass('invalid');
            $('#necesita_loguearse').text("");


            var rootRef = firebase.database().ref().child("Libros");

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

                var titulo = snap.child("Título").val();
                var autor = snap.child("Autor").val();
                var año = snap.child("Año").val();
                var genero = snap.child("Género").val();
                var sinopsis = snap.child("Sinopsis").val();
                var estrellas = snap.child("Estrellas").val();
                var enlace = snap.child("Enlace").val();
                console.log(enlace);
                suma = estrellas + star;
                console.log(estrellas, " ", star, " ", suma);

                estrellas = suma;
                console.log(estrellas);

                // Actualizo la base de datos
                var Vtitulo = $('#titulo_dato').val();
                let database = firebase.database();
                let referencia = database.ref('Libros/' + Vtitulo);

                referencia.set({

                    Título: titulo,
                    Autor: autor,
                    Año: año,
                    Género: genero,
                    Sinopsis: sinopsis,
                    Estrellas: estrellas,
                    Enlace: enlace

                });
                $("#table_body").empty();
                $("#table_body").append("<tr><td>" + titulo + "</td><td>" + autor + "</td><td>" + año + "</td><td>" + genero + "</td><td>" + sinopsis + "</td><td>" + estrellas + "</td><td> <a href='" + enlace + "'> <u> Enlace </u> </a> </td></tr>");

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
            $('#incorrecto').text("ERROR. Debe loguearse para puntuar uno de los libros que se encuentra en nuestra base de datos.");
        }
        
    });
 
}


