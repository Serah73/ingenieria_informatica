

//Muestrar/esconder
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
