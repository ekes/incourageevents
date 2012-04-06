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

  $script->addRunIvrMenu($prompt, $options);
  $script->addGoto('%ivr_option_selected');

  $script->addLabel('no_input_received');
  $script->addLabel('invalid_option');
  $script->addSay('Unknown option selected');
  $script->addGoto('menu');

  $script->addLabel('events');
  $script->addGosub('voipviews_read_view', array('view_name' => 'location_upcoming', 'display_id' => 'voipviews_1', 'args' => json_encode(array($node->nid))));
  $script->addGoto('menu');

  $script->addLabel('redirect');
  $script->addSay(v('Transfering your call.'));
  $script->addDial($phone);
  $script->addGoto('menu');

  $script->addLabel('return');
  return $script;
}
