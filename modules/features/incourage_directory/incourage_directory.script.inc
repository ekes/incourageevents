<?php

/**
 * @file
 *   voipscripts for voipnode.
 */

/**
 * Basic default script to read voipnode contents
 */
function _incourage_directory_location_script($node) {
  $script = new VoipScript('incourage_location');

  $script->addLabel('introduction');

  if ($greeting = voipnode_get_greeting($node)) {
    $script->addSay($greeting);
  }
  else {
    $script->addSay($node->title);
  }

  $script->addLabel('menu');
  $prompt = t('For hear events at this location, dial 1. ');
  $options = array(1 => 'events');
  if (! empty($node->field_phone_text[0]['value'])) {
    $phone = $node->field_phone_text[0]['value'];
    $prompt .= t('To be redirected to the organization phone, dial the star key.');
    $options['*'] = 'redirect';
  }
  $prompt .= t('To go back to the main menu, press the pound key.');
  $options['#'] = 'return';

  $script->addLog('prompt ' . $prompt);
  $script->addLog('options', print_r($options, true));

  $script->addRunIvrMenu($prompt, $options, t('Invalid input. Please try again.'), NULL, 3);
  $script->addGoto('%ivr_option_selected');
  $script->addGoto('return');

  $script->addLabel('events');
  $script->addGosub('voipviews_read_view', array('view_name' => 'location_upcoming', 'display_id' => 'voipviews_1', 'args' => json_encode(array($node->nid))));
  $script->addGoto('menu');

  $script->addLabel('redirect');
  $script->addSay(t('Transfering your call.'));
  $script->addDial($phone);
  $script->addGoto('menu');

  $script->addLabel('return');
  return $script;
}

/**
 * Voipscript callback: for sms msgs.
 */
function _incourage_directory_sms_script() {
  $script = new VoipScript('voipscript_event_sms');
$script->addLog('sms: %inbound_text_contents');
  $script->addSet('request_result', '^incourage_directory_sms_parse(%inbound_text_contents, %caller_number)');
  $script->addSendText("%request_result");
  $script->addHangup('reset');
  return $script;
}

/**
 * Helper function, parse extension from sms, return msg.
 */
function incourage_directory_sms_parse($text, $number) {
  $msg = '';
  // super loose regex will just match the first number (multiple digits too)
  // in the string.
  if (preg_match('/[0-9]+/', $text, $matches)) {
    $eid = $matches[0];
    // if we have an extension
    if ($extension = voipextension_load($eid)) {
      // and it is a node, we aren't doing anything else yet.
      if ($extension['module'] = 'voipnode') {
        if ($extension['extension_type'] == 'event') {
          $msg = incourage_events_sms_reply($extension);
        }
        elseif ($extension['extension_type'] == 'location') {
          $msg = incourage_directory_sms_reply($extension);
        }
      }
    }
    // if no message we got an unknown number for extension
    if ($msg == '') {
      $msg = 'Incourage Events hotline. Invalid extension provided.';
    }
  }
  else {
    $msg = 'To receive details about an event or location send an SMS with the extension number in it.';
  }

  return $msg;
}
