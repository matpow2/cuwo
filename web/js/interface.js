$(document).ready(function(){
    var socket = new WebSocket("ws://localhost:8081");

    socket.onopen = function(){
    $('.nav li').click(function(){
        var ClassArray = {"0":"Warrior","1":"Rogue","2":"Ranger","3":"Mage"};
        socket.send(JSON.stringify({want : 'players',info: {name : 'fill', lvl :'fill'}}));
        socket.onmessage = function (event) {
            var sedata = JSON.parse(event.data);
            if(sedata.response=='players'){
                $('.players tbody').html('');
                for(var i = 0; i < sedata.names.length;i++)
                $('.players tbody').append("<tr><td class='name'>"+sedata.names[i]+'</td><td class="level">'+sedata.levels[i]+'</td><td class="Class">'+ClassArray[sedata.klass[i]]+'</td><td class="Specialization">'+sedata.specialz[i]+'</td></tr>')
            }
    };
    $('table.players tbody tr').click(function(){
        alert("Clicked on"+$(this,'tr td.name').text);
        socket.send(JSON.stringify({want:'kick',name:$(this,'tr td.name').text}))
    });
    });
    window.onunload=function(){socket.close();};
    };
});
