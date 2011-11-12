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
    $location = node_load($node->field_location_reference[0]['nid']);
    $phone = $location->field_phone[0]['value'];
  }
  else {
    if ($greeting = voipnode_get_greeting($node)) {
      $script->addSay($greeting);
    }
    else {
      $body = strip_tags($node->body);
      $script->addSay($body);
    }
    $script->addReturn();
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
watchdog('voipdemo', 'txt: ' . $msg);
  $script->addSay(t('Message sent.'));
  $script->addGoto('options');

  $script->addLabel('contact');
  $script->addSay(t('Transfering your call.'));
watchdog('voipdemo', 'redirect to: ' . $phone);
  $script->addDial($phone);
  $script->addGoto('options');

  $script->addLabel('return');
  return $script;
}

function _voipdemo_welcome() {
  $script = new VoipScript('voipextension_basic_menu');

  $script->addSay(t('Welcome to the Same Boat hotline'));

  $script->addLabel('extension_menu');

  $prompt = t('Please enter the desired extension number followed by the pound key.');

  $script->addLabel('request_extension');
  $script->addGetInput($prompt, 2, '#', 6);
$script->addLog('%input_digits', 'getInput result');
  $script->addGotoIf('no_input_received', "^%input_digits == ''");
  $script->addGotoIf('go_back', "^%input_digits == '*'");
  $script->addGosub('voipextension_play_extension', array('eid' => "%input_digits"));
  $script->addGoto('request_extension');

  $script->addLabel('no_input_received');
  $script->addSay('No input received. Please try again.');
  $script->addGoto('request_extension');

  $script->addLabel('go_back');
  $script->addReturn();

  return $script;
}

