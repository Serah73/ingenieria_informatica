
var instance = M.Carousel.init({
  fullWidth: false,
  indicators: true

});

// Or with jQuery

$('.carousel.carousel-slider').carousel({
  fullWidth: false,
  indicators: true
});




// DOM elements
const loggedOutLinks = document.querySelectorAll('.logged-out');
const loggedInLinks = document.querySelectorAll('.logged-in');
const accountDetails = document.querySelector('.account-details');

//USER INTERFACE
const setupUI = (user) => {
  if (user) {

    const html = `
        <div>Has iniciado sesión con ${user.email}</div>
      `;
    accountDetails.innerHTML = html;

    // toggle user UI elements
    loggedInLinks.forEach(item => item.style.display = 'block');
    loggedOutLinks.forEach(item => item.style.display = 'none');
  } else {
    // clear account info
    accountDetails.innerHTML = '';
    // toggle user elements
    loggedInLinks.forEach(item => item.style.display = 'none');
    loggedOutLinks.forEach(item => item.style.display = 'block');
  }
};


// setup materialize components
//Modals on materialize
document.addEventListener('DOMContentLoaded', function () {

  var modals = document.querySelectorAll('.modal');
  M.Modal.init(modals);

  var items = document.querySelectorAll('.collapsible');
  M.Collapsible.init(items);

});


