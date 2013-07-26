<?php
$jsonFile = 'http://mp2.dk/cuwo/servers.json';
$jsonFileAsString = file_get_contents($jsonFile);
$serverList = json_decode($jsonFileAsString);

foreach($serverList as $cuwoServer): ?>
<tr>
<td><?=htmlspecialchars($cuwoServer->name)?></td>
<td><?=htmlspecialchars($cuwoServer->mode)?></td>
<td><?=$cuwoServer->players?>/<?=$cuwoServer->max?></td>
<td><?=$cuwoServer->ip?></td>
<td><span class="hidden-desktop hidden-phone hidden-tablet"><?=$cuwoServer->location?></span><img src="data:image/gif;base64,R0lGODlhAQABAIAAAAAAAP///yH5BAEAAAAALAAAAAABAAEAAAIBRAA7" class="flag flag-<?=strtolower($cuwoServer->location)?>" alt="<?=$cuwoServer->location?>" /></td>
</tr>
<?php endforeach; ?>