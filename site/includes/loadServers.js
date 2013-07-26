function ajaxRequest() {
  $.getJSON('http://mp2.dk/cuwo/servers.json', function(jsonData) {
    var table = document.getElementById('serverListTable');
    while(table.hasChildNodes()) {
      table.removeChild(table.firstChild);
    }

    $.each(jsonData, function() {
      var row = table.insertRow();
      var name = row.insertCell(0);
      var mode = row.insertCell(1);
      var players = row.insertCell(2);
      var ip = row.insertCell(3);
      var location = row.insertCell(4);
      name.innerHTML = $('<div/>').text(this.name).html();
      mode.innerHTML = $('<div/>').text(this.mode).html();
      players.innerHTML = $('<div/>').text(this.players + '/' + this.max).html();
      ip.innerHTML = $('<div/>').text(this.ip).html();
      var loc = $('<div/>').text(this.location).html();
      location.innerHTML = '<span class="hidden-desktop hidden-phone hidden-tablet">' + loc + '</span> <img src="data:image/gif;base64,R0lGODlhAQABAIAAAAAAAP///yH5BAEAAAAALAAAAAABAAEAAAIBRAA7" class="flag flag-' + loc.toLowerCase() + '" alt="' + loc + '" />';

    });
  });
  setTimeout('ajaxRequest()', 20000);
}