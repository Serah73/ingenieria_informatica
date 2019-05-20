
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
    var sinopsis = snap.child("Sinopsis").val();
    console.log(sinopsis);

    $("#table_body").append("<tr><td>" + titulo + "</td><td>" + autor + "</td><td>" + año + "</td><td>" + genero + "</td><td>" + sinopsis + "</td><td>" + estrellitas + "</td></tr>");
});


function calificar(star) {
    var user = firebase.auth().currentUser;
    if (user != null) {
        var rootRef = firebase.database().ref().child("Libros");


        rootRef.on("child_added", snap => {

            const Vtitulo2 = $('#titulo_dato').val();
            var titulo = snap.child("Título").val();
            const Vautor2 = $('#autor_libro').val();
            console.log("Comprueba: ");
            console.log(Vautor2);
            var autor_ = snap.child("Autor").val();
            console.log(autor_);

            if ((titulo == Vtitulo2) && (Vautor2 == autor_)){
                bool_titulo = true;
                console.log("RESULTADO::::::::::::");
                console.log(bool_titulo);

                var autor = snap.child("Autor").val();

                var año = snap.child("Año").val();

                var genero = snap.child("Género").val();

                var sinopsis = snap.child("Sinopsis").val();

                var estrellas = snap.child("Estrellas").val();


                console.log("___________________________ CALCULANDO ________________________");

                console.log(estrellas);
                console.log(star);
                suma = estrellas + star;
                console.log(suma);
                estrellas = suma;

                // Actualizo la base de datos
                const Vtitulo = $('#titulo_dato').val();
                let database = firebase.database();
                let referencia = database.ref('Libros/' + Vtitulo);

                referencia.set({

                    Título: titulo,
                    Autor: autor,
                    Año: año,
                    Género: genero,
                    Sinopsis: sinopsis,
                    Estrellas: estrellas

                });
                $("#table_body").empty();    
                $("#table_body").append("<tr><td>" + titulo + "</td><td>" + autor + "</td><td>" + año + "</td><td>" + genero + "</td><td>" + sinopsis + "</td><td>" + estrellas + "</td></tr>");

            } else {
                bool_titulo = false;
            }


        });
    }
    else{
        console.log("No estás registrado");
    }
}


