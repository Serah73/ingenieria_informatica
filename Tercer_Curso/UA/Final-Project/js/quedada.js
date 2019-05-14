function comprobar(){
    
    //  if((date($('#fecha_quedada').val()) && time($('#Hora').val())) === true) //poner aquí las restricciones
    //      document.getElementById('send').style.visibility = 'visible';
    
    if((date() === true ) /*&& (time() === true)*/){ //poner aquí las restricciones
        console.log("todo bien");
        document.getElementById('send').style.visibility = 'visible';}
    else{
        
       
        alert("Algun formato no esta relleno o tiene un formato incorrecto.");

        if(date($('#fecha_quedada').val()) === false)
             document.getElementById("campo_quedada").style.color = "#ff0000";
        /*if((time($('#Hora').val())) === false)
           document.getElementById("campo_hora").style.color = "#ff0000";*/
    }
        
}


function pushData() {
    
    // console.log('hola');
    
    var VUsuario = $('#usuario').val();
    console.log(VUsuario);
   
    const VQuedada = $('#fecha_quedada').val();;
    console.log(VQuedada);
    const VHora = $('#hora').val();
    console.log(VHora);
    const VLibro = $('#field1').val();
    console.log(VLibro);
    const VLugar = $('#lugar').val();
    console.log(VLugar);
    
    const VComentario = $('#comentario').val();
    console.log(VComentario);
   /* const VTelefono = $('#tlf').val();
    console.log(VTelefono);
    const VEmail = $('#mail').val();
    console.log(VEmail);
    */

    let database = firebase.database();
    let referencia = database.ref('quedadas/' + VUsuario);
    //Escribir un documento
    referencia.set({
        
        Usuario: VUsuario,
        Quedada: VQuedada,
        Hora: VHora,
        Lugar: VLugar,
        Libro: VLibro,
        Comentario: VComentario,
       // Telefono: VTelefono,
       // Correo: VEmail,
    });
    
   
};


function date(){
    var date = document.getElementById('fecha_quedada').value;
    var CurrentDate = new Date();
    GivenDate = new Date(date);

    if(GivenDate < CurrentDate){
        return false;
        alert('Given date is smaller than the current date.');
    }
    
    return true;
}

function time(){
    var time= document.getElementById('hora').value;
    var h = time.getHours();
    if (h<8 || h>20){
        return false;
        alert ('Time has to be between 8:00-20:00')
    }
    return true;
}


     $(document).ready(function(){
    var next = 1;
    $(".add-more").click(function(e){
        e.preventDefault();
        var addto = "#field" + next;
        var addRemove = "#field" + next;///(next);
        next++; //= next + 1;
        var newIn = '<input autocomplete="off" class="input form-control" id="field' + next + '" name="field' + next + '" type="text">';
        var newInput = $(newIn);
        var removeBtn = '<button id="remove' + (next - 1) + '" class="btn btn-danger remove-me" >-</button></div><div id="field">';
        var removeButton = $(removeBtn);
        $(addto).after(newInput);
        $(addRemove).after(removeButton);
        $("#field" + next).attr('data-source',$(addto).attr('data-source'));
        $("#count").val(next);  
        
            $('.remove-me').click(function(e){
                e.preventDefault();
                var fieldNum = this.id.charAt(this.id.length-1);
                var fieldID = "#field" + fieldNum;
                $(this).remove();
                $(fieldID).remove();
            });
    });
    

    
});

function adjust_textarea(h) {
    h.style.height = "50px";
    h.style.height = (h.scrollHeight)+"px";
}



/*$(document).ready(function () {

    $('input[type=password]').focusout(function () {
        $('#pswd_info').show();
        
        let pswd = $("#pswd")[0].value
        
       //validate the length
        if (pswd.length < 8) {
            $('#length').removeClass('valid').addClass('invalid');
            hidden = true;
        } else {
            $('#length').removeClass('invalid').addClass('valid');
        }

        // validate letra
        if (pswd.match(/[A-z]/)) {
            $('#letra').removeClass('invalid').addClass('valid');
            
        } else {
            $('#letra').removeClass('valid').addClass('invalid');
            hidden = true;
        }

        // validate mayuscula letra
        if (pswd.match(/[A-Z]/)) {
            $('#mayuscula').removeClass('invalid').addClass('valid');
        } else {
            $('#mayuscula').removeClass('valid').addClass('invalid');
            hidden = true;
        }

        //validate numero
        if (pswd.match(/\d/)) {
            $('#numero').removeClass('invalid').addClass('valid');
            hidden = true;
        } else {
            $('#numero').removeClass('valid').addClass('invalid');
        }
    });
    
   
});*/



   


