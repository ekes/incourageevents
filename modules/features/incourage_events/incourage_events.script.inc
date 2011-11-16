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
    $body .= strip_tags($location);
    $body .= strip_tags($node->body);
    $script->addSay($body);
  }
  $script->addGoto('options');

  $script->addLabel('sms');
  $msg = strip_tags($node->title) . ' ';
  $msg .= date_format_date($date_object, 'short') . ' ';
  $msg .= strip_tags($location) . ' ';
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

/**
 * Voipscript callback: for sms msgs.
 */
function _incourage_events_sms_script() {
  $script = new VoipScript('voipscript_event_sms');
$script->addLog('sms: %inbound_text_contents');
  $script->addSet('request_result', '^incourage_events_sms_parse(%inbound_text_contents, %caller_number)');
  $script->addSendText("%request_result");
  $script->addHangup('reset');
  return $script;
}

/**
 * Helper function, parse extension from sms, return msg.
 */
function incourage_events_sms_parse($text, $number) {
  $msg = '';
  // super loose regex will just match the first number (multiple digits too)
  // in the string.
  if (preg_match('/[0-9]+/', $t, $matches)) {
    $eid = $matches[0];
    // if we have an extension
    if ($extension = voipextension_load($eid)) {
      // and it is a node, we aren't doing anything else yet.
      if ($extension['module'] = 'voipnode') {
        $node = node_load($extension['module_id']);
        // and it's an event, we aren't doing anything else yet.
        if ($node->type == 'event') {
          list($location, $phone) = _incourage_events_script_location($node);
          $msg = strip_tags($node->title) . ' ';
          $msg .= date_format_date($date_object, 'short') . ' ';
          $msg .= strip_tags($location);
        }
      }
    }
    // if no message we got an unknown number for extension
    if ($msg == '') {
      $msg = 'Extension number not recognized. Please send SMS with number with no spaces.';
    }
  }
  else {
    $msg = 'To recieve details about an event send an SMS with the extension number in it.';
  }

  return $msg;
}

/**
 * Script helper function to return correct location information.
 */
function _incourage_events_script_location($node) {
  if (!empty($node->field_location_reference[0]['nid'])) {
    $location_node = node_load($node->field_location_reference[0]['nid']);
    $location = $location_node->title . ', ' . $location_node->field_address_street[0]['value'];
    $phone = $location_node->field_phone_text[0]['value'];
  }
  else {
    $location = $node->field_location[0]['value'];
    $phone = '';
  }
 
  return array($location, $phone);
}
