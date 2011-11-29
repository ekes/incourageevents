<?php
/**
 * @file
 *   Views row template for upcoming events date.
 *
 * Calculates repeeating dates either (a) to the end of a pdfbulletin
 *  schedule period - the pdfbulletin object is attached to the view
 *  by pdfbulletin.module; or (b) if there is no pdfbulletin attached
 *  until the last event date of the view.
 * Note: requires PHP 5.3 date objects, but in proceedural style.
 *  It is probably possible to recreate with just date.module functions.
 */

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
$output = $output . '.';

// depending on view field settings the ical include is not loaded
module_load_include('inc', 'date_api', 'date_api_ical');

// gather timezone information, for db storage and field display.
$timezone_db = $field->content_field['timezone_db'];
// @todo only looked at our site handling; see also date_get_timezone
// got handling; need timezone.
$timezone = $field->content_field['tz_handling'];
if (empty($timezone) || !date_timezone_is_valid($timezone)) {
  $timezone = date_default_timezone_name();
}

// first date to calculate repetitions from is the first date of the event.
$first = $row->{$field->field_alias};
/* last date either...
if (isset($view->pdfbulletin)) {
  // ...pdfbulletin schedule period added to first event date
  $start = $view->result[0]->{$field->field_alias};
  $start = date_convert($start, DATE_DATETIME, DATE_UNIX);
  $start += $view->pdfbulletin->schedule['frequency'];
  $last = date_convert($start, DATE_UNIX, DATE_DATETIME);
}
else { */
  // ...or last event date
  $last = $view->result[count($view->result) - 1]->{$field->field_alias};
// }
// repeat rule
$rrule_field = $field->table_alias . '_' . $field->additional_fields['field_date_rrule'];
$rrule = $row->{$field->table_alias . '_' . $field->additional_fields['field_date_rrule']};

if (! empty($rrule)) {
  // calculate repeat dates in the period.
  $rrule_array = date_repeat_split_rrule($rrule);
  $repeat_dates = date_repeat_calc($rrule_array[0]['DATA'], $first, $last, $rrule_array[1], $timezone_db, $rrule_array[2]);
  // the dates include the first event itself
  if (count($repeat_dates) > 1) {
    $dates = array();
    $dates_text = array();
    foreach ($repeat_dates as $date) {
      // for each of the repeat dates make the human readable parts
      $datetime = date_make_date($date, $timezone_db);
      date_timezone_set($datetime, timezone_open($timezone));
      $parts = array();
      $parts['year'] = date_format_date($datetime, 'custom', 'Y');
      $parts['month'] = date_format_date($datetime, 'custom', 'n');
      $parts['day'] = date_format_date($datetime, 'custom', 'j');
      $parts['ordinal'] = date_format_date($datetime, 'custom', 'S');
      $parts['time'] = date_format_date($datetime, 'custom', 'g:ia');
      $dates[] = $parts;
    }
    // first date in array is the event self, then cycle through other events...
    $lastdate = array_shift($dates);
    $lastdate['month'] = '';
    foreach ($dates as $date) {
      // ... adding any changing parts; ie. if they are the same avoid repetition.
      $text = '';
      if ($lastdate['time'] != $date['time']) {
        $text .= ' ' . t('at @date', array('@date' => $date['time']));
      }
      if ($lastdate['year'] != $date['year']) {
        $text = '/' . $date['year'] . $text;
      }
      if ($lastdate['day'] != $date['day'] || $lastdate['month'] != $date['month']) {
        // date_t is good for short strings like month abbrv
        // $text .= date_t($date['month'], 'month_abbr') . ' ';
        $text = $date['month'] . '/' . $date['day'] . $text;
      }
      $dates_text[] = trim($text);
      $lastdate = $date;
    }
    $output .= ' <span class="repeat-dates">' . t('Also occurs on: %dates', array('%dates' => implode(', ', $dates_text))) . '.</span>'; 
  }
}
?>
<?php print $output; ?>
