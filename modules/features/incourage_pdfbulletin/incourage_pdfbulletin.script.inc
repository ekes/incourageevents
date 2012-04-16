<?php

/**
 * @file
 *   voipscripts for upcoming events.
 */

/**
 * Basic default script to read voipnode contents
 */
function _incourage_upcoming_script() {
  $script = new VoipScript('incourage_upcoming');

  $script->addLabel('begin');


  // Is there a way this could be integrated with the terms
  // themselves?
  $terms = array(
    1 => 'employment-related events',
    2 => 'food-related events',
    5 => 'fun and family events',
    3 => 'health-related events',
    4 => 'events not included in any of the categories above',
  );
  $options = array(
    1 => 1,
    2 => 2,
    3 => 5,
    4 => 3,
    5 => 4,
  );
  $prompt = '';
  foreach ($options as $option => $tid) {
    $description = $terms[$tid];
    $prompt .= "For $description , Press $option";
  }
  $options['#'] = 'return';
  $prompt .= 'To go back to the main menu, press the pound key.';

  $script->addRunIvrMenu($prompt, $options);
  $script->addGoto('%ivr_option_selected');
  // I would like to do an array_key_exists here, how to pass $options to
  // addGotoIf?
  foreach ($options as $key => $tid) {
    $script->addSet('tid', $tid);
    $script->addGotoIf('upcoming_topic', "^%ivr_option_selected == $key");
  }
  $script->addSet('tid', '');
  $script->addGoto('%ivr_option_selected');
  $script->addGoto('begin');

  $script->addLabel('upcoming_topic');
  $script->addSay('Upcoming events');
  $script->addGosub('voipviews_read_view', array('view_name' => 'upcoming', 'display_id' => 'voipviews_1', 'filter' => json_encode(array('filters' => array('tid' => '%tid')))));
  $script->addGoto('begin');

  $script->addLabel('no_input_received');
  $script->addLabel('return');
  $script->addReturn();
  return $script;

  
}
 
