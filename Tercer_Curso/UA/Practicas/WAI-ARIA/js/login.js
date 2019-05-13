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
    const iniciar = document.getElementById('iniciar');
    // const btnSignUp = document.getElementById('btnSignUp');
    const cerrar = document.getElementById('cerrar');

    // Añadir Evento login
    iniciar.addEventListener('click', e => {
        //Obtener email y pass
        const email = mail.value;
        const pass = pswd.value;
        const auth = firebase.auth();
        // Sign in
        const promise = auth.signInWithEmailAndPassword(email, pass);
        promise.catch(e => console.log(e.message));
        
    });

    // Añadir evento signup
    // btnSignUp.addEventListener('click', e => {
    //     // Obtener email y pass
    //     // TODO: comprobar que el email sea real
    //     const email = txtEmail.value;
    //     const pass = txtPassword.value;
    //     const auth = firebase.auth();
    //     // Sign in
    //     const promise = auth.createUserWithEmailAndPassword(email, pass);
    //     promise.catch(e => console.log(e.message));
    // });

    cerrar.addEventListener('click', e => {
        firebase.auth().signOut();
    });

    // Añadir un listener en tiempo real
    firebase.auth().onAuthStateChanged(firebaseUser => {
        if (firebaseUser) {
            console.log(firebaseUser);
            cerrar.classList.remove('hide');
        } else {
            console.log('no logueado');
            cerrar.classList.add('hide');

        }
    });
}());

//Muestra de botones arriba derecha
firebase.auth().onAuthStateChanged(function(user) {
    if (user) {

        document.getElementById('logout').style.visibility = 'visible';
        document.getElementById('exito').style.display = 'block';

        document.getElementById('login').style.display = 'none';
        document.getElementById('signup').style.display = 'none';
        document.getElementById('switch_hide').style.display = 'none';
    } else {

        document.getElementById('logout').style.visibility = 'hidden';
        document.getElementById('exito').style.display = 'none';

        document.getElementById('login').style.display = 'block';
        document.getElementById('signup').style.display = 'block';
        document.getElementById('switch_hide').style.display = 'block';
    }
});

