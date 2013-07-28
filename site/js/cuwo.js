var doneGit = false , doneServers = false, reload_action;

$(function() {
  doSort();
  var id = window.location.hash || '#about';
  page(id);
  $('.nav-link').click(function() {
    page($(this).data('page'));
    return false;
  });
});

function showContent(id) {
  $('.nav-link').parent().removeClass('active');
  $('a[data-page=' + id + ']').parent().addClass('active');
  $('.page-content').hide();
  $('div[data-page=' + id + ']').show();
  window.location.hash = id;
}
function page(id) {
  if (id == '#servers') {
    if (!doneServers) getServers(); doneServers = true;
    showContent('#servers');
    $('ul#refresh').show();
  } else {
    if (!doneGit) getCommits(); doneGit = true;
    clearTimeout(reload_action);
    showContent('#about');
    $('ul#refresh').hide();
  }
}

function getCommits() {
  $.getJSON('https://api.github.com/repos/matpow2/cuwo/commits?per_page=5&callback=?', function(data) {
    var table = $('#commits');
    var rowHolder = table.find('tbody');
    rowHolder.find('tr').remove();

    if (data.meta.status === 200) {
      $.each(data.data, function(index, commit) {
        var row = $('<tr/>');

        var author = '<a href="' + commit.author.html_url + '" target="_blank">' + commit.author.login + '</a>';
        $('<td/>').html(author).appendTo(row);

        var timestamp = new Date(commit.commit.author.date);
        $('<td/>').html('<small class="muted">' + timestamp.toString() + '</small><br>' + commit.commit.message.replace('\n', '<br>', 'g')).appendTo(row);

        var shortSHA = commit.sha.substr(0,10);
        var sha = '<a href="' + commit.html_url + '" target="_blank">' + shortSHA + '</a>';
        $('<td/>').html(sha).appendTo(row);

        rowHolder.append(row);
      });
    } else {
      var row = $('<tr/>');
      $('<td/>').html('GitHub API limit reached! <a href="https://github.com/matpow2/cuwo/commits/" target="_blank" title="View on GitHub">Click here</a> to view the commit history on GitHub or wait for the limit to reset.').attr('colspan', 3).appendTo(row);
      rowHolder.append(row);
    }
  });
}

function getServers() {
  $.getJSON('http://mp2.dk/cuwo/servers.json', function(jsonData) {
    var table = $('#servers');

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
    reload_action = setTimeout('getServers()', 20000);
  });
}
function doSort() {
  $('#servers').tablesorter({
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
}