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
    $location = $location_node->title . ', ' . $location_node->field_address_street[0]['value'] . ', ' . $location_node->field_address_city[0]['value'];
    $phone = $location_node->field_phone_text[0]['value'];
  }
  else {
    $location = $node->field_location[0]['value'];
  }

  if ($title = voipnode_get_title($node)) {
    $script->addSay($title) . '. ';
  }

  if ($greeting = voipnode_get_greeting($node)) {
    $script->addSay($greeting);
  }
  else {
    $body = $title . '. ';
    $body .= strip_tags($node->body) . '. ';
    // To get the next date re-use the logic in date_token_repeat.
    $date_text = 'This event happens on [field_date-next-type:monthdaytime]';
    $body .= token_replace_multiple($date_text, array('global' => NULL, 'node' => $node));
    $body .= 'at ' . strip_tags($location) . '. ';
    $script->addSay($body);
  }

  $script->addLabel('options');
  $script->addBeep();
  $script->addSay('Event menu: ');
  $invalid_input_msg = t('Invalid input. Please try again.');
  if (empty($phone)) {
    $script->addRunIvrMenu(
      t('To hear details again, dial 1. To receive an SMS of details, dial 2. To return to the previous menu press the # key.'), 
      array(1 => 'introduction', 2=> 'sms', '#' => 'return'),
      $invalid_input_msg, NULL, 3
    );
  }
  else {
    $script->addRunIvrMenu(
      t('To hear details again, dial 1. To receive an SMS of details, dial 2. To contact the organizers dial 3. To return to the previous menu press the # key.'), 
      array(1 => 'introduction', 2 => 'sms', 2 => 'contact', '#' => 'return'),
      $invalid_input_msg, NULL, 3
    );
  }
  $script->addGoto('%ivr_option_selected');
  $script->addGoto('return');

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

