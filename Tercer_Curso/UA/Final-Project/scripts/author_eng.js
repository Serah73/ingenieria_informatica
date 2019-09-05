
// Servicios de APIs Firebase


var storageService = firebase.storage();
var uploader = document.getElementById('uploader');
var downloader = document.getElementById('download');


// Forma 1 de descarga
var descarga = storageService.ref('Participantes/Libro_del_mes.txt');

downloader.addEventListener('click', function(){
    descarga.getDownloadURL().then(function(url){
        console.log("descargando");
    
        console.log(url);
        document.getElementById('prueba').innerHTML = '<a href="' + url + '"> Download link </a> <style>  prueba { color: #FF0000; } </style>'
        var pruebas = document.getElementById('prueba');

        pruebas.style.background = 'black'; 
    })
})

function subidaArchivo() {
    var authService = firebase.auth().currentUser;
    console.log("llamando");
    console.log(authService);
    if (authService != null) {
        console.log("Logueado");
        //manejador de evento para el input file
        document.getElementById('campoarchivo').addEventListener('change', function (evento) {
            evento.preventDefault();
            console.log("archivo");
            var archivo = evento.target.files[0];
            console.log(archivo);
            subirArchivo(archivo);
        });

        //manejadores de eventos para los botones de control de la subida
        document.getElementById('pausar').addEventListener('click', function () {
            if (uploadTask && uploadTask.snapshot.state == 'running') {
                uploadTask.pause();
                console.log('pausada');
            }
        });
        document.getElementById('reanudar').addEventListener('click', function () {
            if (uploadTask && uploadTask.snapshot.state == 'paused') {
                uploadTask.resume();
                console.log('reanudada');
            }
        });
        document.getElementById('cancelar').addEventListener('click', function () {
            if (uploadTask && (uploadTask.snapshot.state == 'paused' || uploadTask.snapshot.state == 'running')) {
                if (uploadTask.snapshot.state == 'paused') {
                    uploadTask.resume();
                }
                uploadTask.cancel();
                console.log('cancelada');
            };
        });
    } else {
        console.log("Tienes que iniciar sesión.");
        $('#incorrecto').addClass('invalid');
        $('#incorrecto').text("ERROR. You must log in to upload a file.");
        $('#campoarchivo').value = ' ';
    }




}

// defino el uploadTask como variable global, porque lo voy a necesitar
var uploadTask;
function subirArchivo(archivo) {
    var refStorage = storageService.ref('Participantes').child(archivo.name);
    uploadTask = refStorage.put(archivo);
    console.log("uploadTack: " + uploadTask);
    // El evento donde comienza el control del estado de la subida
    uploadTask.on('state_changed', registrandoEstadoSubida, errorSubida, finSubida);

    //Callbacks para controlar los distintos instantes de la subida
    function registrandoEstadoSubida(uploadSnapshot) {
        console.log("registrando subida");
        var calculoPorcentaje = (uploadSnapshot.bytesTransferred / uploadSnapshot.totalBytes) * 100;
        calculoPorcentaje = Math.round(calculoPorcentaje);
        var percentage = (uploadSnapshot.bytesTransferred / uploadSnapshot.totalBytes) * 100;
        uploader.value = percentage;
        registrarPorcentaje(calculoPorcentaje);


    }
    function errorSubida(err) {
        console.log('Error al subir el archivo', err);
    }
    function finSubida() {
        console.log('Subida completada');
        console.log('El archivo está subido. Su ruta: ', uploadTask.snapshot.downloadURL);
        enlaceSubido(uploadTask.snapshot.downloadURL);
    }

}



// mostramos el porcentaje en cada instante de la subida
function registrarPorcentaje(porcentaje) {
    var elMensaje = document.getElementById('mensaje');
    var textoMensaje = '<p>Porcentaje de subida: ' + porcentaje + '%</p>';
    elMensaje.innerHTML = textoMensaje;
}

// mostramos el link para acceso al archivo al final de la subida
function enlaceSubido(enlace) {
    console.log("hey enlace");
    document.getElementById('enlace').href = enlace;
    document.getElementById('archivo').style.display = 'block';
    document.getElementById('archivo').style.background = 'black';
}





