<?php

/**
 * @file
 *   voipscripts for upcoming events.
 */

/**
 * Offer to read upcoming events, or go to extensions menu.
 */
function _incourage_upcoming_script() {
  $script = new VoipScript('incourage_upcoming');

  $script->addSay('Welcome to the Incourage events hotline.');

  $script->addLabel('begin');
  $script->addSay('Main menu.');

  // Is there a way this could be integrated with the terms
  // themselves?
  $terms = array(
    1 => 'employment-related events',
    2 => 'food-related events',
    5 => 'fun and family related events',
    3 => 'health-related events',
    4 => 'events not included in any of the categories above',
  );
  $topics = $options = array(
    1 => 1,
    2 => 2,
    3 => 5,
    4 => 3,
    5 => 4,
  );
  $prompt = '';
  foreach ($options as $option => $tid) {
    $description = $terms[$tid];
    $prompt .= "To listen to $description , Press $option. ";
  }
  $options['*'] = 'extension_menu';
  $prompt .= 'To go to a specific extension number, dial the star key.';

  $script->addRunIvrMenu($prompt, $options, t('Invalid input. Please try again.'), NULL, 3);
  // I would like to do an array_key_exists here, how to pass $options to
  // addGotoIf?
  foreach ($topics as $key => $tid) {
    $script->addSet('tid', $tid);
    $script->addGotoIf('upcoming_topic', "^%ivr_option_selected == $key");
  }
  $script->addSet('tid', '');
  $script->addGoto('%ivr_option_selected');
  $script->addGoto('return');

  $script->addLabel('upcoming_topic');
  $script->addSay('Upcoming events');
  $script->addGosub('voipviews_read_view', array('view_name' => 'upcoming', 'display_id' => 'voipviews_1', 'filters' => json_encode(array('tid' => array('%tid')))));
  $script->addGoto('begin');

  $script->addLabel('extension_menu');
  $script->addGoto('incourage_extensions');
  $script->addGoto('begin');

  $script->addLabel('no_input_received');
  $script->addLabel('return');
  $script->addReturn();
  return $script;

  
}
 
