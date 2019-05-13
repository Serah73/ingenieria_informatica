(function () {

    //Inicializar Firebase
    var config = {
        apiKey: "AIzaSyDLJUI3VYgL53qdHOXEzlNlPi1uR2K0TcY",
        authDomain: "uya3ro.firebaseapp.com",
        databaseURL: "https://uya3ro.firebaseio.com",
        projectId: "uya3ro",
        storageBucket: "uya3ro.appspot.com",
        messagingSenderId: "905524222112"
    };

    firebase.initializeApp(config);

    const mail = document.getElementById('mail');
    const pswd = document.getElementById('pswd');
    const send = document.getElementById('enviar');
  
  
    // Añadir evento signup
    send.addEventListener('click', e => {
        // Obtener email y pass
        // TODO: comprobar que el email sea real
        const email = mail.value;
        const pass = pswd.value;
        const auth = firebase.auth();
        // Sign in
        const promise = auth.createUserWithEmailAndPassword(email, pass);
        promise.catch(e => console.log(e.message));
    });



    // Añadir un listener en tiempo real
    firebase.auth().onAuthStateChanged(firebaseUser => {
        if (firebaseUser) {
            console.log(firebaseUser);
            cerrar.classList.remove('hide');
        } else {
            console.log('nooo logueado');
            cerrar.classList.add('hide');

        }
    });
}());