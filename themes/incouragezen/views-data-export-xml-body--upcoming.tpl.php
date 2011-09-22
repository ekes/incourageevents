<?php
/**
 * @file views-view-table.tpl.php
 * Template to display a view as a table.
 *
 * - $title : The title of this group of rows.  May be empty.
 * - $rows: An array of row items. Each row is an array of content
 *   keyed by field ID.
 * - $header: an array of headers(labels) for fields.
 * - $themed_rows: a array of rows with themed fields.
 * @ingroup views_templates
 */
?>
  <info><?php 
print date("g:ia")."\n";
print "Wisconsin Rapids\n";
// HACK: for some reason the views "Items to display" isn't being respected
$themed_rows_shortened = array_slice($themed_rows,0,5);
foreach ($themed_rows_shortened as $count => $row){
  foreach ($row as $field => $content){ 
    print $content."\n";
  }
}
?></info>
