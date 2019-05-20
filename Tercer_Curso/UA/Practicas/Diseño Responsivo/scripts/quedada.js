function comprobar() {

    if (date() === true)
        document.getElementById('send').style.visibility = 'visible';
    else {
        console.log("ERROR");
        if (date($('#fecha_quedada').val()) === false)
            document.getElementById("campo_quedada").style.color = "#ff0000";
    }
  


}


function pushData() {
    var user = firebase.auth().currentUser;
    if (user != null) {
        user.providerData.forEach(function (profile) {
            console.log("Sign-in provider: " + profile.providerId);
            console.log("  Provider-specific UID: " + profile.uid);
            console.log("  Name: " + profile.displayName);
            console.log("  Email: " + profile.email);
            console.log("  Photo URL: " + profile.photoURL);
            var VCorreo = $('#correo').val();
            console.log(VCorreo);
            if (profile.email == VCorreo ) {
                console.log("logueado");

                const VQuedada = $('#fecha_quedada').val();;
                const VHora = $('#hora').val();
                const VLibro = $('#field1').val();
                const VLugar = $('#lugar').val();
            
            
            
                let database = firebase.database();
                let referencia = database.ref('Quedadas/' + VQuedada);
            
                referencia.set({
            
                    Cuenta: VCorreo,
                    Quedada: VQuedada,
                    Hora: VHora,
                    Lugar: VLugar,
                    Libro: VLibro
            
                });


            } else {
                console.log("NO logueado");
            }
        });
       
    }

};


function date() {
    var date = document.getElementById('fecha_quedada').value;
    var CurrentDate = new Date();
    GivenDate = new Date(date);

    if (GivenDate < CurrentDate) {
        return false;
        alert('Given date is smaller than the current date.');
    }

    return true;
}

function time() {
    var time = document.getElementById('hora').value;
    var h = time.getHours();
    if (h < 8 || h > 20) {
        return false;
        alert('Time has to be between 8:00-20:00')
    }
    return true;
}


$(document).ready(function () {
    var next = 1;
    $(".add-more").click(function (e) {
        e.preventDefault();
        var addto = "#field" + next;
        var addRemove = "#field" + next;
        next++;
        var newIn = '<input autocomplete="off" class="input form-control" id="field' + next + '" name="field' + next + '" type="text">';
        var newInput = $(newIn);
        var removeBtn = '<button id="remove' + (next - 1) + '" class="btn btn-danger remove-me" >-</button></div><div id="field">';
        var removeButton = $(removeBtn);
        $(addto).after(newInput);
        $(addRemove).after(removeButton);
        $("#field" + next).attr('data-source', $(addto).attr('data-source'));
        $("#count").val(next);

        $('.remove-me').click(function (e) {
            e.preventDefault();
            var fieldNum = this.id.charAt(this.id.length - 1);
            var fieldID = "#field" + fieldNum;
            $(this).remove();
            $(fieldID).remove();
        });
    });

});

function adjust_textarea(h) {
    h.style.height = "50px";
    h.style.height = (h.scrollHeight) + "px";
}







