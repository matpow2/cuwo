var doneGit = false , doneServers = false, reload_action;

$(function() {
  $('.tip').tooltip();
  doSort();
  $.pages();
});

function getCommits() {
  $.getJSON('https://api.github.com/repos/matpow2/cuwo/commits?per_page=5&callback=?', function(data) {
    var table = $('#commits');
    var rowHolder = table.find('tbody');
    rowHolder.find('tr').remove();

    if (data.meta.status === 200) {
      $.each(data.data, function(index, commit) {
        var row = $('<tr/>');

        var avatar = $('<img/>')
          .attr('src', 'http://www.gravatar.com/avatar/' + commit.author.gravatar_id + '?s=50&d=https://a248.e.akamai.net/assets.github.com%2Fimages%2Fgravatars%2Fgravatar-user-420.png')
          .attr('alt', commit.author.login)
          .attr('title', commit.author.login)
          .addClass('avatar')
          .tooltip();
        var author = $('<a/>')
          .attr('href', commit.author.html_url)
          .attr('target', '_blank')
          .append(avatar);
        $('<td/>').html(author).appendTo(row);

        var timestamp = $('<small/>').addClass('muted').text(new Date(commit.commit.author.date).toString());
        var messageParts = commit.commit.message.split('\n');
        var messageShort = messageParts[0];
        messageParts.splice(0, 1);
        var description = $('<div/>')
          .attr('id', 'message' + index)
          .attr('style', 'display:none')
          .html(entities(messageParts.join('\n')).replace(/\n/g, '<br>') || '<br><em class="muted">No description available</em>');
        var message = $('<div/>')
          .append(timestamp)
          .append('<br>')
          .append(entities(messageShort))
          .append(description);
        $('<td/>').html(message)
          .attr('onclick', '$("#message' + index + '").slideToggle(250)')
          .attr('style', 'cursor:pointer')
          .appendTo(row);

        var sha = $('<a/>')
          .attr('href', commit.html_url)
          .attr('target', '_blank')
          .text(commit.sha.substr(0,10));
        $('<td/>').html(sha).appendTo(row);

        rowHolder.append(row);
      });
    } else {
      var row = $('<tr/>');
      $('<td/>').html('GitHub API limit reached! <a href="https://github.com/matpow2/cuwo/commits/" target="_blank" title="View on GitHub">Click here</a> to view the commit history on GitHub.')
        .attr('colspan', 3)
        .appendTo(row);
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
      var country = $('<span/>').text(loc).addClass('hidden-desktop hidden-phone hidden-tablet');
      var flag = $('<img/>')
        .attr('src', 'data:image/gif;base64,R0lGODlhAQABAIAAAAAAAP///yH5BAEAAAAALAAAAAABAAEAAAIBRAA7')
        .attr('alt', loc)
        .attr('title', loc)
        .addClass('flag flag-' + loc.toLowerCase());
      $('<td/>').append(country).append(flag).appendTo(row);

      rowHolder.append(row);
    });

    if (Object.keys(jsonData).length <= 40) $('#pagination').hide(); else $('#pagination').show();

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

function entities(input) {
  return input.replace(/&/g, '&amp;').replace(/</g, '&lt;').replace(/>/g, '&gt;');
}