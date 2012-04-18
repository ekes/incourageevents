<?php

/**
 * Implementation of hook_fieldgroup_default_groups().
 */
function incourage_directory_fieldgroup_default_groups() {
  $groups = array();

  // Exported group: group_address
  $groups['location-group_address'] = array(
    'group_type' => 'standard',
    'type_name' => 'location',
    'group_name' => 'group_address',
    'label' => 'Address',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'weight' => '7',
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
      ),
    ),
    'weight' => '7',
    'fields' => array(
      '0' => 'field_address_street',
      '1' => 'field_address_city',
      '2' => 'field_address_postcode',
    ),
  );

  // Exported group: group_voipnode_settings
  $groups['location-group_voipnode_settings'] = array(
    'group_type' => 'standard',
    'type_name' => 'location',
    'group_name' => 'group_voipnode_settings',
    'label' => 'VoIP Extension Settings',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset_collapsible',
        'description' => '',
      ),
      'display' => array(
        'weight' => '7',
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
    'weight' => '7',
    'fields' => array(
      '0' => 'field_voipnode_adesc',
      '1' => 'field_voipnode_agreet',
      '2' => 'field_voipnode_aname',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Address');
  t('VoIP Extension Settings');

  return $groups;
}
