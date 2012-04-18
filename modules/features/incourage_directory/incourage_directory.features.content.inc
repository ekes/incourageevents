<?php

/**
 * Implementation of hook_content_default_fields().
 */
function incourage_directory_content_default_fields() {
  $fields = array();

  // Exported field: field_address_city
  $fields['location-field_address_city'] = array(
    'field_name' => 'field_address_city',
    'type_name' => 'location',
    'display_settings' => array(
      'weight' => '9',
      'parent' => 'group_address',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_address_city][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'City',
      'weight' => '9',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_address_postcode
  $fields['location-field_address_postcode'] = array(
    'field_name' => 'field_address_postcode',
    'type_name' => 'location',
    'display_settings' => array(
      'weight' => '10',
      'parent' => 'group_address',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_address_postcode][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Zip code',
      'weight' => '10',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_address_street
  $fields['location-field_address_street'] = array(
    'field_name' => 'field_address_street',
    'type_name' => 'location',
    'display_settings' => array(
      'weight' => '8',
      'parent' => 'group_address',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_address_street][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Street',
      'weight' => '8',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_official_name
  $fields['location-field_official_name'] = array(
    'field_name' => 'field_official_name',
    'type_name' => 'location',
    'display_settings' => array(
      'weight' => '5',
      'parent' => '',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_official_name][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Official name',
      'weight' => '5',
      'description' => 'Only required if different from the popular name.',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_phone_text
  $fields['location-field_phone_text'] = array(
    'field_name' => 'field_phone_text',
    'type_name' => 'location',
    'display_settings' => array(
      'weight' => '17',
      'parent' => '',
      'label' => array(
        'format' => 'hidden',
      ),
      'teaser' => array(
        'format' => 'hidden',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'hidden',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_phone_text][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Direct phone number',
      'weight' => '17',
      'description' => 'Phone number of the location, area code first. Example: (715) 234.5678.',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_point
  $fields['location-field_point'] = array(
    'field_name' => 'field_point',
    'type_name' => 'location',
    'display_settings' => array(
      'weight' => '15',
      'parent' => '',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'openlayers_wkt',
    'required' => '0',
    'multiple' => '0',
    'module' => 'openlayers_cck',
    'active' => '1',
    'openlayers_cck_feature_types' => array(
      'point' => 'point',
      'path' => 0,
      'polygon' => 0,
    ),
    'widget' => array(
      'openlayers_cck_preset_map' => 'default_wrapids',
      'openlayers_behaviors' => array(
        'openlayers_behavior_zoomtolayer' => array(
          'enabled' => 0,
          'options' => array(
            'zoomtolayer' => 'openlayers_cck_vector_layer',
            'point_zoom_level' => '5',
          ),
        ),
      ),
      'default_value' => array(
        '0' => array(
          'openlayers_wkt' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Map',
      'weight' => '15',
      'description' => '',
      'type' => 'openlayers_wkt_widget',
      'module' => 'openlayers_cck',
    ),
  );

  // Exported field: field_voipnode_adesc
  $fields['location-field_voipnode_adesc'] = array(
    'field_name' => 'field_voipnode_adesc',
    'type_name' => 'location',
    'display_settings' => array(
      'weight' => 0,
      'parent' => 'group_voipnode_settings',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'audiofield_embedded',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'audiofield_embedded',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'audiofield_embedded',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'audiofield_embedded',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'filefield',
    'required' => '0',
    'multiple' => '0',
    'module' => 'filefield',
    'active' => '1',
    'list_field' => '0',
    'list_default' => 1,
    'description_field' => '0',
    'widget' => array(
      'file_extensions' => 'mp3',
      'file_path' => '',
      'progress_indicator' => 'bar',
      'max_filesize_per_file' => '',
      'max_filesize_per_node' => '',
      'phonerecorderfield_number' => NULL,
      'phonerecorderfield_script' => NULL,
      'phonerecorderfield_text' => NULL,
      'label' => 'Audio Description',
      'weight' => 0,
      'description' => '',
      'type' => 'audiofield_widget',
      'module' => 'audiofield',
    ),
  );

  // Exported field: field_voipnode_agreet
  $fields['location-field_voipnode_agreet'] = array(
    'field_name' => 'field_voipnode_agreet',
    'type_name' => 'location',
    'display_settings' => array(
      'weight' => 0,
      'parent' => 'group_voipnode_settings',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'audiofield_embedded',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'audiofield_embedded',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'audiofield_embedded',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'audiofield_embedded',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'filefield',
    'required' => '0',
    'multiple' => '0',
    'module' => 'filefield',
    'active' => '1',
    'list_field' => '0',
    'list_default' => 1,
    'description_field' => '0',
    'widget' => array(
      'file_extensions' => 'mp3',
      'file_path' => '',
      'progress_indicator' => 'bar',
      'max_filesize_per_file' => '',
      'max_filesize_per_node' => '',
      'phonerecorderfield_number' => NULL,
      'phonerecorderfield_script' => NULL,
      'phonerecorderfield_text' => NULL,
      'label' => 'Audio Greeting',
      'weight' => 0,
      'description' => '',
      'type' => 'audiofield_widget',
      'module' => 'audiofield',
    ),
  );

  // Exported field: field_voipnode_aname
  $fields['location-field_voipnode_aname'] = array(
    'field_name' => 'field_voipnode_aname',
    'type_name' => 'location',
    'display_settings' => array(
      'weight' => 0,
      'parent' => 'group_voipnode_settings',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'audiofield_embedded',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'audiofield_embedded',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'audiofield_embedded',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'audiofield_embedded',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'filefield',
    'required' => '0',
    'multiple' => '0',
    'module' => 'filefield',
    'active' => '1',
    'list_field' => '0',
    'list_default' => 1,
    'description_field' => '0',
    'widget' => array(
      'file_extensions' => 'mp3',
      'file_path' => '',
      'progress_indicator' => 'bar',
      'max_filesize_per_file' => '',
      'max_filesize_per_node' => '',
      'phonerecorderfield_number' => NULL,
      'phonerecorderfield_script' => NULL,
      'phonerecorderfield_text' => NULL,
      'label' => 'Audio Name',
      'weight' => 0,
      'description' => '',
      'type' => 'audiofield_widget',
      'module' => 'audiofield',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Audio Description');
  t('Audio Greeting');
  t('Audio Name');
  t('City');
  t('Direct phone number');
  t('Map');
  t('Official name');
  t('Street');
  t('Zip code');

  return $fields;
}
