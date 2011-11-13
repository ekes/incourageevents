<?php

/**
 * @file
 *   voipscripts for voipnode.
 */

/**
 * Basic default script to read voipnode contents
 */
function _incourage_events_event_script($node) {
  $script = new VoipScript('incourage_event');

  $script->addLabel('introduction');
  if ($title = voipnode_get_title($node)) {
    $script->addSay($title);
  }

  if (!empty($node->field_location_reference[0]['nid'])) {
    $location = node_load($node->field_organiser_reference[0]['nid']);
    $phone = $location->field_phone_text[0]['value'];
  }
    
  if ($greeting = voipnode_get_greeting($node)) {
    $script->addSay($greeting);
  }
  else {
    $body = strip_tags($node->body);
    $script->addSay($body);
  }

  $date_field = $node->field_date[0];
  $date_object = date_make_date($date_field['value'], $date_field['timezone_db']);
  $timezone = new DateTimeZone($date_field['timezone']);
  $date_object->setTimezone($timezone);

  $script->addLabel('options');
  if (empty($phone)) {
    $script->addRunIvrMenu(t('For event details, dial 1. To receive an SMS of details, dial 2. To return to the previous menu press the # key.'), array(1 => 'details', 2=> 'sms', '#' => 'return'));
  }
  else {
    $script->addRunIvrMenu(t('For event details, dial 1. To receive an SMS of details, dial 2. To contact the organizers dial 3. To return to the previous menu press the # key.'), array(1 => 'details', 2=> 'sms', 3 => 'contact', '#' => 'return'));
  }
  $script->addGoto('%ivr_option_selected');

  $script->addLabel('details');
  if ($greeting = voipnode_get_greeting($node)) {
    $script->addSay($greeting);
  }
  else {
    $body = date_format_date($date_object, 'long') . '. ';
    $body .= strip_tags($node->body);
    $script->addSay($body);
  }
  $script->addGoto('options');

  $script->addLabel('sms');
  $msg = strip_tags($node->title) . ' ';
  $msg .= date_format_date($date_object, 'short') . ' ';
  $msg .= strip_tags($location->title) . ' ';
  $script->addSendText($msg);
  $script->addSay(t('Message sent.'));
  $script->addGoto('options');

  $script->addLabel('contact');
  $script->addSay(t('Transfering your call.'));
  $script->addDial($phone);
  $script->addGoto('options');

  $script->addLabel('return');
  return $script;
}
