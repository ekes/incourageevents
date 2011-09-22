<?php
// $Id$
 /**
  * This template is used to print a single field in a view. It is not
  * actually used in default Views, as this is registered as a theme
  * function which has better performance. For single overrides, the
  * template is perfectly okay.
  *
  * Variables available:
  * - $view: The view object
  * - $field: The field handler object that can process the input
  * - $row: The raw SQL result that can be used
  * - $output: The processed output that will normally be used.
  *
  * When fetching output from the $row, this construct should be used:
  * $data = $row->{$field->field_alias}
  *
  * The above will guarantee that you'll always get the correct data,
  * regardless of any changes in the aliasing that might happen if
  * the view is modified.
  */

$date = $row->node_data_field_date_field_date_value;
$time = strtotime($date);
$today = strtotime(date('M j, Y'));
$reldays = ($time - $today)/86400;
$day_str = date("D", $time);
if ($reldays >= 0 && $reldays < 1) {
    $day_str = 'Today';
} else if ($reldays >= 1 && $reldays < 2) {
    $day_str = 'Tomorrow';
}

$utcTz = new DateTimeZone('UTC');
$grandRapidsTz = new DateTimeZone('America/Chicago');
$eventDateTime = new DateTime($date,$utcTz);
$eventDateTime->setTimezone($grandRapidsTz); 

print $day_str." ".$eventDateTime->format("ga");

?>
