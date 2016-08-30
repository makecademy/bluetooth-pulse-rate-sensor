setInterval(function() {

    $.get('/pulse_rate_sensor/bpm', function( json_data ) {
        if (json_data.bpm){
            $("#bpm").html(json_data.bpm);    
        }
    });

}, 500);