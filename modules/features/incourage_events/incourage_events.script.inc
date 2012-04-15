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

  if (!empty($node->field_location_reference[0]['nid'])) {
    $location_node = node_load($node->field_organiser_reference[0]['nid']);
    $location = $location_node->title . ', ' . $location_node->field_address_street[0]['value'];
    $phone = $location_node->field_phone_text[0]['value'];
  }
  else {
    $location = $node->field_location[0]['value'];
  }
    
  $date_field = $node->field_date[0];
  $date_object = date_make_date($date_field['value'], $date_field['timezone_db']);
  $timezone = new DateTimeZone($date_field['timezone']);
  $date_object->setTimezone($timezone);
  
  if ($title = voipnode_get_title($node)) {
    $script->addSay($title) . '. ';
  }

  $script->addLabel('options');
  $script->addBeep();
  $script->addSay('Event menu: ');
  if (empty($phone)) {
    $script->addRunIvrMenu(t('For event details, dial 1. To receive an SMS of details, dial 2. To return to the previous menu press the # key.'), array(1 => 'details', 2=> 'sms', '#' => 'return'));
  }
  else {
    $script->addRunIvrMenu(t('For event details, dial 1. To receive an SMS of details, dial 2. To contact the organizers dial 3. To return to the previous menu press the # key.'), array(1 => 'details', 2=> 'sms', 3 => 'contact', '#' => 'return'));
  }
  $script->addGoto('%ivr_option_selected');
  $script->addSay('Selection not recognized.');
  $script->addGoto('options');

  $script->addLabel('details');
  if ($greeting = voipnode_get_greeting($node)) {
    $script->addSay($greeting);
  }
  else {
    $body = $title . '. ';
    $body .= strip_tags($node->body) . '. ';
//    $body .= 'Takes event happens on ' . date_format_date($date_object, 'voip') . ', '; 
    $body .= 'This event happens on ' . date_format_date($date_object, 'custom', variable_get('date_format_voip', 'Y-m-d')) . ', '; 
    $body .= 'at ' . strip_tags($location) . '. ';
    $script->addSay($body);
  }
  $script->addGoto('options');

  $script->addLabel('sms');
  $msg = incourage_events_format_sms($node);
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

