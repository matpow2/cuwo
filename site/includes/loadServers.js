function ajaxRequest() {
  var xmlhttpRequest;
  if (window.XMLHttpRequest) {
    xmlhttpRequest = new XMLHttpRequest();
  }
  else if (window.ActiveXObject) {
    try {
      xmlhttpRequest = new ActiveXObject("Msxml2.XMLHTTP");
    }
    catch(e) {
      try {
      xmlhttpRequest = new ActiveXObject("Microsoft.XMLHTTP");
      }
      catch(e) {}
    }
  }
  else {
    return false;
  }        
        
  xmlhttpRequest.onreadystatechange = function() {
    if (xmlhttpRequest.readyState === 4 && xmlhttpRequest.status === 200) {
      document.getElementById("serverListTable").innerHTML = xmlhttpRequest.responseText;
      setTimeout('ajaxRequest()', 20000);
    }
  }
  xmlhttpRequest.open('GET', 'includes/serversOnlineTable.php', true);
  xmlhttpRequest.send();
}