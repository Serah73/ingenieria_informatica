
   function hey(){
    $(document).ready(function(){
        $("#send").click(function(){
            $.getJSON("https://jsonplaceholder.typicode.com/comments?id="+$('#id').val(), function(result){
                $("#data").html("");
                $.each(result, function(i, field){
                    $("#data").append(JSON.stringify(field) + "<br><br>");
                });
            });
        });


    });

}