<?php

/**
 * Incourage extension menu.
 */
function _incourage_voipdrupal_welcome() {
  $script = new VoipScript('incourage_voipdrupal');

  $script->addLabel('extension_menu');

  $prompt = t('Please enter the desired extension number followed by the pound key. To go back to the main menu, dial star.');

  $script->addLabel('request_extension');
  $script->addGetInput($prompt, 5, '#', 6);
  $script->addGotoIf('no_input_received', "^%input_digits == ''");
  $script->addGotoIf('upcoming_events', "^%input_digits == '*'");
  $script->addGosub('voipextension_play_extension', array('eid' => "%input_digits"));
  $script->addGoto('extension_menu');

  $script->addLabel('no_input_received');
  // do some counting to prevent the eternal loop
  $script->addGoto('extension_menu');

  $script->addLabel('upcoming_events');
  $script->addLabel('return');
  return $script;
}

/**
 * Silent version of _voipextension_get_play_extension_script().
 *
 * @todo should make this part of voipextension.
 */
function _incourage_voipdrupal_play_extension_script($eid, $options=array()) {
  $script = new VoipScript('voipextension_play_extension');
  // using voipscript %number replacement
  $script->setVar('number', $eid);

  if (($extension = voipextension_load($eid)) && $extension['enabled']) {
    $gosub = voipextension_get_script($extension);
    $arguments = array_merge($gosub['script_arguments'], $options);
    // include the extension in the arguments
    $arguments['eid'] = $eid;
    $script->addGosub($gosub['script_name'], $arguments);
  }
  else {
    if (! $unknown = variable_get('voipextension_unknown_msg', FALSE)) {
      $unknown = t('Unknown extension %number. ');
    }
    $script->addSay($unknown);
  }
  $script->addReturn();
 
  return $script;
}


