<?php

/**
 * Implementation of hook_content_default_fields().
 */
function incourage_events_content_default_fields() {
  $fields = array();

  // Exported field: field_cost
  $fields['event-field_cost'] = array(
    'field_name' => 'field_cost',
    'type_name' => 'event',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
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
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '1',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => 5,
      'size' => '30',
      'default_value' => array(
        '0' => array(
          'value' => 'Free',
          '_error_element' => 'default_value_widget][field_cost][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Cost',
      'weight' => '7',
      'description' => 'Currency and amount; or \'Free\'.',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_date
  $fields['event-field_date'] = array(
    'field_name' => 'field_date',
    'type_name' => 'event',
    'display_settings' => array(
      'weight' => '-3',
      'parent' => '',
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'date',
    'required' => '1',
    'multiple' => '1',
    'module' => 'date',
    'active' => '1',
    'granularity' => array(
      'year' => 'year',
      'month' => 'month',
      'day' => 'day',
      'hour' => 'hour',
      'minute' => 'minute',
    ),
    'timezone_db' => 'UTC',
    'tz_handling' => 'site',
    'todate' => 'optional',
    'repeat' => 1,
    'repeat_collapsed' => '1',
    'default_format' => 'medium',
    'widget' => array(
      'default_value' => 'now',
      'default_value_code' => '',
      'default_value2' => 'same',
      'default_value_code2' => '',
      'input_format' => 'm/d/Y - g:i:sa',
      'input_format_custom' => '',
      'increment' => '1',
      'text_parts' => array(),
      'year_range' => '-1:+3',
      'label_position' => 'above',
      'label' => 'Date',
      'weight' => 0,
      'description' => '',
      'type' => 'date_popup_repeat',
      'module' => 'date',
    ),
  );

  // Exported field: field_location
  $fields['event-field_location'] = array(
    'field_name' => 'field_location',
    'type_name' => 'event',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
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
          '_error_element' => 'default_value_widget][field_location][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Location text',
      'weight' => '1',
      'description' => 'This field overrides both Venue and Organizer fields. It might be used whenever the desired venue or organizer is not listed above. Examples: Playground by the church, Tom\'s house, 123 Orchard St, etc.',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_location_reference
  $fields['event-field_location_reference'] = array(
    'field_name' => 'field_location_reference',
    'type_name' => 'event',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
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
    'type' => 'nodereference',
    'required' => '0',
    'multiple' => '0',
    'module' => 'nodereference',
    'active' => '1',
    'referenceable_types' => array(
      'location' => 'location',
      'event' => 0,
      'event_feed' => 0,
      'pdfbulletin' => 0,
    ),
    'advanced_view' => '--',
    'advanced_view_args' => '',
    'widget' => array(
      'autocomplete_match' => 'contains',
      'size' => 60,
      'default_value' => array(
        '0' => array(
          'nid' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Venue',
      'weight' => '-1',
      'description' => 'The location where the event is going to be held.',
      'type' => 'nodereference_select',
      'module' => 'nodereference',
    ),
  );

  // Exported field: field_organiser_reference
  $fields['event-field_organiser_reference'] = array(
    'field_name' => 'field_organiser_reference',
    'type_name' => 'event',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
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
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'nodereference',
    'required' => '0',
    'multiple' => '0',
    'module' => 'nodereference',
    'active' => '1',
    'referenceable_types' => array(
      'location' => 'location',
      'event' => 0,
      'event_feed' => 0,
      'pdfbulletin' => 0,
    ),
    'advanced_view' => '--',
    'advanced_view_args' => '',
    'widget' => array(
      'autocomplete_match' => 'contains',
      'size' => 60,
      'default_value' => array(
        '0' => array(
          'nid' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Organizer',
      'weight' => 0,
      'description' => 'This field is only required when the organization responsible for the event is different from the one listed in the Venue field.',
      'type' => 'nodereference_select',
      'module' => 'nodereference',
    ),
  );

  // Exported field: field_sms_text
  $fields['event-field_sms_text'] = array(
    'field_name' => 'field_sms_text',
    'type_name' => 'event',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
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
      'token' => array(
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
    'max_length' => '140',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => 5,
      'size' => '140',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_sms_text][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'SMS notification text',
      'weight' => '5',
      'description' => 'Optional alternative text to send in SMS notifications for the event.',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_voipnode_adesc
  $fields['event-field_voipnode_adesc'] = array(
    'field_name' => 'field_voipnode_adesc',
    'type_name' => 'event',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
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
  $fields['event-field_voipnode_agreet'] = array(
    'field_name' => 'field_voipnode_agreet',
    'type_name' => 'event',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
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
  $fields['event-field_voipnode_aname'] = array(
    'field_name' => 'field_voipnode_aname',
    'type_name' => 'event',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
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
  t('Cost');
  t('Date');
  t('Location text');
  t('Organizer');
  t('SMS notification text');
  t('Venue');

  return $fields;
}
