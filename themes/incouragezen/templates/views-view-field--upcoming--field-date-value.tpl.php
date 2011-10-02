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
module_load_include('inc', 'date_api', 'date_api_ical');
$timezone_db = $field->content_field['timezone_db'];
// @todo only looked at our site handling; see also date_get_timezone
// got handling; need timezone.
$timezone = $field->content_field['tz_handling'];
if (empty($timezone) || !date_timezone_is_valid($timezone)) {
  $timezone = date_default_timezone_name();
}
$first = $row->{$field->field_alias};
$last = $view->result[count($view->result) - 1]->{$field->field_alias};
$rrule_field = $field->table_alias . '_' . $field->additional_fields['field_date_rrule'];
$rrule = $row->{$field->table_alias . '_' . $field->additional_fields['field_date_rrule']};
if (! empty($rrule)) {
  $rrule_array = date_repeat_split_rrule($rrule);
  $repeat_dates = date_repeat_calc($rrule_array[0]['DATA'], $first, $last, $rrule_array[1], $timezone_db, $rrule_array[2]);
  if (count($repeat_dates) > 1) {
    $dates = array();
    $dates_text = array();
    foreach ($repeat_dates as $date) {
      $datetime = date_make_date($date, $timezone_db);
      date_timezone_set($datetime, timezone_open($timezone));
      $parts = array();
      $parts['year'] = date_format_date($datetime, 'custom', 'Y');
      $parts['month'] = date_format_date($datetime, 'custom', 'M');
      $parts['day'] = date_format_date($datetime, 'custom', 'j');
      $parts['ordinal'] = date_format_date($datetime, 'custom', 'S');
      $parts['time'] = date_format_date($datetime, 'custom', 'g:ia');
      $dates[] = $parts;
    }
    $lastdate = array_shift($dates);
    foreach ($dates as $date) {
      $text = '';
      if ($lastdate['month'] != $date['month']) {
        $text .= date_t($date['month'], 'month_abbr') . ' ';
      }
      if ($lastdate['day'] != $date['day']) {
        $text .= $date['day'] . t($date['ordinal']) . ' ';
      }
      if ($lastdate['year'] != $date['year']) {
        $text .= $date['year'] . ' ';
      }
      if ($lastdate['time'] != $date['time']) {
        $text .= $date['time'];
      }
      $dates_text[] = trim($text);
      $lastdate = $date;
    }
    $output .= ' <div class="repeat-dates">' . t('and also %dates', array('%dates' => implode(', ', $dates_text))) . '</div>'; 
  }
}
?>
<?php print $output; ?>
