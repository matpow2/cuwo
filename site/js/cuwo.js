$(function() {
  loadServerList();

  $('#serverlist').tablesorter({
    theme: 'bootstrap',
    widthFixed: true,
    headerTemplate : '{content} {icon}',
    widgets: [ 'uitheme', 'zebra' ],
    sortList: [[2,1]]
  })
  .tablesorterPager({
    container: $('.pager'),
    cssGoto: '.pagenum',
    output: 'Page {page} of {totalPages} ({startRow}&ndash;{endRow} / {totalRows})',
    size: 40
  });
});

var reload_action;
function loadServerList() {
  $.getJSON('http://mp2.dk/cuwo/servers.json', function(jsonData) {
    var table = $('#serverlist');

    var rowHolder = table.find('tbody');
    rowHolder.find('tr').remove();

    $.each(jsonData, function() {
      var row = $('<tr/>');

      $('<td/>').text(this.name).appendTo(row);
      $('<td/>').text(this.mode).appendTo(row);
      $('<td/>').text(this.players + '/' + this.max).appendTo(row);
      $('<td/>').text(this.ip).appendTo(row);

      var loc = $('<div/>').text(this.location).html();
      var image = $('<img/>').attr('src', 'data:image/gif;base64,R0lGODlhAQABAIAAAAAAAP///yH5BAEAAAAALAAAAAABAAEAAAIBRAA7').attr('alt', loc).attr('title', loc).addClass('flag flag-' + loc.toLowerCase());
      $('<td/>').append($('<span/>').text(loc).addClass('hidden-desktop hidden-phone hidden-tablet')).append(image).appendTo(row);

      rowHolder.append(row);
    });

    if (Object.keys(jsonData).length < 40) $('#pagination').hide(); else $('#pagination').show();

    table.trigger('update', [true]);

    clearTimeout(reload_action);
    reload_action = setTimeout('loadServerList()', 20000);
  });
}