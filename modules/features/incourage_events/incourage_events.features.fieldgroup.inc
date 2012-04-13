<?php

/**
 * Implementation of hook_fieldgroup_default_groups().
 */
function incourage_events_fieldgroup_default_groups() {
  $groups = array();

  // Exported group: group_location
  $groups['event-group_location'] = array(
    'group_type' => 'standard',
    'type_name' => 'event',
    'group_name' => 'group_location',
    'label' => 'Location',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset_vertical_tab',
        'description' => '',
      ),
      'display' => array(
        'weight' => '5',
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'description' => '',
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
      ),
    ),
    'weight' => '5',
    'fields' => array(
      '0' => 'field_location_reference',
      '1' => 'field_organiser_reference',
      '2' => 'field_location',
    ),
  );

  // Exported group: group_voipnode_settings
  $groups['event-group_voipnode_settings'] = array(
    'group_type' => 'standard',
    'type_name' => 'event',
    'group_name' => 'group_voipnode_settings',
    'label' => 'VoIP Extension Settings',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset_collapsible',
        'description' => '',
      ),
      'display' => array(
        'weight' => '6',
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'description' => '',
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
      ),
    ),
    'weight' => '6',
    'fields' => array(
      '0' => 'field_voipnode_adesc',
      '1' => 'field_voipnode_agreet',
      '2' => 'field_voipnode_aname',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Location');
  t('VoIP Extension Settings');

  return $groups;
}
