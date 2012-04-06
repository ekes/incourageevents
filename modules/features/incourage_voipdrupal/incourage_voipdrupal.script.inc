<?php

function _incourage_voipdrupal_welcome() {
  $script = new VoipScript('incourage_voipdrupal');

  $script->addSay(t('Welcome to the incourage events hotline'));

  $script->addLabel('extension_menu');

  $prompt = t('Please enter the desired extension number followed by the pound key.');

  $script->addLabel('request_extension');
  $script->addGetInput($prompt, 5, '#', 6);
  $script->addGotoIf('no_input_received', "^%input_digits == ''");
  $script->addGotoIf('go_back', "^%input_digits == '*'");
  $script->addGosub('voipextension_play_extension', array('eid' => "%input_digits"));
  $script->addGoto('extension_menu');

  $script->addLabel('no_input_received');
  $script->addSay('No input received. Please try again.');
  $script->addGoto('request_extension');

  $script->addLabel('go_back');
  $script->addReturn();

  return $script;
}
