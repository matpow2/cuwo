$(document).ready(function(){
    var socket = new WebSocket("ws://localhost:8081");
    var ClassArray = {"0":"Warrior","1":"Rogue","2":"Ranger","3":"Mage"};
    var PlayersArray ={"names":[],"levels":[],"klass":[], "specialz":[]};

    socket.onopen = function(){

        socket.send(JSON.stringify({want : 'players'}));

        socket.onmessage = function (event) {
            var sedata = JSON.parse(event.data);

            if(sedata.response=='players'){

                for(var i= 0; i <  sedata.names.length; i++){
                    var j = PlayersArray.names.indexOf(sedata.names[i]);
                    if (j == -1){
                        PlayersArray.names.push(sedata.names[i]);
                        PlayersArray.levels.push(sedata.levels[i]);
                        PlayersArray.klass.push(sedata.klass[i]);
                        PlayersArray.specialz.push(sedata.specialz[i]);
                        $('table.players tbody').append("<tr data-name=\"" +PlayersArray.names[i]+"\" ><td class='name'>"+PlayersArray.names[i]+'</td>' +
                                                        '<td class="level">'+PlayersArray.levels[i]+'</td>' +
                                                        '<td class="class">'+ClassArray[PlayersArray.klass[i]]+'</td>' +
                                                        '<td class="specialization">'+PlayersArray.specialz[i]+'</td></tr>');
                    }
                    else{
                        PlayersArray.names[j]=sedata.names[i];
                        PlayersArray.levels[j]=sedata.levels[i];
                        PlayersArray.klass[j]=sedata.klass[i];
                        PlayersArray.specialz[j]=sedata.specialz[i];
                        $("table.players tbody tr[data-name=" +PlayersArray.names[j]+ "] td.name").text(PlayersArray.names[j]);
                        $("table.players tbody tr[data-name=" +PlayersArray.names[j] + "] td.level").text(PlayersArray.levels[j]);
                        $("table.players tbody tr[data-name=" +PlayersArray.names[j] + "] td.class").text(PlayersArray.klass[j]);
                        $("table.players tbody tr[data-name=" +PlayersArray.names[j] + "] td.specialization").text(PlayersArray.specialz[j]);
                    }
                }
                //TODO Alert for leaving player
                var deleted =[];
                if(PlayersArray.names.length != 0){
                    for(var i=0;i<PlayersArray.names.length;i++){
                        var j = sedata.names.indexOf(PlayersArray.names[i]);
                        if(j == -1){
                            deleted.push(PlayersArray.names.splice(i,1));
                            $("table.players tbody tr[data-name="+ deleted[0] +"]").remove();
                            deleted.push(PlayersArray.levels.splice(i,1));
                            deleted.push(PlayersArray.klass.splice(i,1));
                            deleted.push(PlayersArray.specialz.splice(i,1));
                        }

                    }
                }
            }

        };

        $('table.players tbody tr').click(function(){
        alert("Clicked on"+$(this,'tr td.name').text);
        socket.send(JSON.stringify({want:'kick',name:$(this,'tr td.name').text}))
        });

    window.onunload=function(){socket.close();};
    };
});
