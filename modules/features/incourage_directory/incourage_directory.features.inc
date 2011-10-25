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
      'title_label' => t('Name'),
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
