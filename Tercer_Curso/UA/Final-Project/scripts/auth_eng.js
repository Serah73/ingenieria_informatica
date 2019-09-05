

// listen for auth status changes
auth.onAuthStateChanged(user => {
    if (user) {
        setupUI(user);
    } else {
        setupUI();
    }
});

$( document ).ready(function() {
    console.log( "ready!" );
    $("#modal-signup").on("hidden.bs.modal", function () {
        console.log("adios");
    });
});




// signup
const signupForm = document.querySelector('#signup-form');
signupForm.addEventListener('submit', (e) => {
    e.preventDefault();
    // get user info
    const email = signupForm['signup-email'].value;
    const password = signupForm['signup-password'].value;

    // sign up the user & add firestore data
    auth.createUserWithEmailAndPassword(email, password).then(cred => {

        const modal = document.querySelector('#modal-signup');

        $('#li_1').removeClass('invalid')
        $('#li_1').removeClass('valid')

        $('#li_2').removeClass('invalid')
        $('#li_2').removeClass('valid')

        $('#li_3').removeClass('invalid')
        $('#li_3').removeClass('valid')

        $('#li_4').removeClass('invalid')
        $('#li_4').removeClass('valid')

        M.Modal.getInstance(modal).close();
        signupForm.reset();
        signupForm.querySelector('.error').innerHTML = ''
    }).catch(err => {
        
        // signupForm.querySelector('.error').innerHTML = err.message;

    });
});



// logout
const logout = document.querySelector('#logout');
logout.addEventListener('click', (e) => {

    e.preventDefault();
    auth.signOut();
    $('#loginRdy').removeClass('invalid')
    $('#loginRdy').text("Enter your password in the previous field.");
});


const logout1 = document.querySelector('#logout1');
logout1.addEventListener('click', (e) => {
    
    e.preventDefault();
    auth.signOut();
    $('#loginRdy').removeClass('invalid')
    $('#loginRdy').text("Enter your password in the previous field.");
  
});




// login
const loginForm = document.querySelector('#login-form');
loginForm.addEventListener('submit', (e) => {
    e.preventDefault();

    // get user info
    const email = loginForm['login-email'].value;
    const password = loginForm['login-password'].value;

    // log the user in
    auth.signInWithEmailAndPassword(email, password).then((cred) => {
        // close the login modal & reset form
        const modal = document.querySelector('#modal-login');

        //test
        $('#loginRdy').removeClass('invalid')
        $('#loginRdy').text("Enter your password in the previous field.");
        console.log("aquiii");
        $('#incorrecto').removeClass('invalid');
        $('#incorrecto').text("");

        $('#necesita_loguearse').removeClass('invalid');
        $('#necesita_loguearse').text("");
        
        //fin test

        M.Modal.getInstance(modal).close();
        loginForm.reset();
        loginForm.querySelector('.error').innerHTML = '';

    }).catch(err => {
        console.log('error 2')
        $('#loginRdy').addClass('invalid');
        $('#loginRdy').text("Bad credentials. Check your data.")
    });

});


function recuperarpassword() {

    var auth = firebase.auth();
    var emailAddress = $('#login-email').val();

    auth.sendPasswordResetEmail(emailAddress).then(function () {   // Email enviado. 

        alert("A mail has been sent to your account. Please check the email.")

    })

        .catch(function (error) {
            console.log(error);
        })
}