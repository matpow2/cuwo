function escapeHTML(text) {
    return String(text).replace(/&/g, "&amp;")
               .replace(/</g, "&lt;")
               .replace(/>/g, "&gt;")
               .replace(/"/g, "&quot;")
               .replace(/'/g, "&#039;");
}

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
      name.innerHTML = escapeHTML(this.name);
      mode.innerHTML = escapeHTML(this.mode);
      players.innerHTML = escapeHTML(this.players + '/' + this.max);
      ip.innerHTML = escapeHTML(this.ip);
      location.innerHTML = '<span class="hidden-desktop hidden-phone hidden-tablet">' + escapeHTML(this.location) + '</span> <img src="data:image/gif;base64,R0lGODlhAQABAIAAAAAAAP///yH5BAEAAAAALAAAAAABAAEAAAIBRAA7" class="flag flag-' + escapeHTML(this.location).toLowerCase() + '" alt="' + escapeHTML(this.location) + '" />';

    });
  });
  setTimeout('ajaxRequest()', 20000);
}