<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function incourage_directory_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => 1);
  }
  elseif ($module == "openlayers" && $api == "openlayers_presets") {
    return array("version" => 1);
  }
  elseif ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function incourage_directory_node_info() {
  $items = array(
    'location' => array(
      'name' => t('Location'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Popular name'),
      'has_body' => '1',
      'body_label' => t('Description'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_rules_defaults().
 */
function incourage_directory_rules_defaults() {
  return array(
    'rules' => array(
      'rules_geocode_when_node_added_with_location_text' => array(
        '#type' => 'rule',
        '#set' => 'event_node_presave',
        '#label' => 'Geocode: when node added with location text',
        '#active' => 1,
        '#weight' => '0',
        '#categories' => array(
          '0' => 'location geocode',
          'incourage_directory' => 'incourage_directory',
        ),
        '#status' => 'default',
        '#conditions' => array(
          '0' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'Created content is Location',
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content',
                ),
              ),
              'module' => 'Node',
            ),
            '#name' => 'rules_condition_content_is_type',
            '#settings' => array(
              'type' => array(
                'location' => 'location',
              ),
              '#argument map' => array(
                'node' => 'node',
              ),
            ),
            '#type' => 'condition',
          ),
        ),
        '#actions' => array(
          '0' => array(
            '#type' => 'action',
            '#settings' => array(
              'sources' => array(
                'field_address_street' => 'field_address_street',
                'field_address_city' => 'field_address_city',
                'field_address_postcode' => 'field_address_postcode',
              ),
              'destination' => 'field_point',
              'prefix' => '',
              'suffix' => 'Wisconsin, United States',
              '#argument map' => array(
                'node' => 'node',
              ),
            ),
            '#name' => 'rules_geocoder_action_geocode_fields',
            '#info' => array(
              'label' => 'Geocode a field or a combination of fields',
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content',
                ),
              ),
              'module' => 'Rules Geocoder',
            ),
            '#weight' => 0,
          ),
        ),
        '#version' => 6003,
      ),
    ),
    'rule_sets' => array(
      'rules_geocode' => array(
        'arguments' => array(
          'node' => array(
            'label' => 'Content',
            'type' => 'node',
          ),
        ),
        'label' => 'Geocode',
        'status' => 'default',
        'categories' => array(
          '0' => 'location geocode',
          'incourage_directory' => 'incourage_directory',
        ),
      ),
    ),
  );
}
