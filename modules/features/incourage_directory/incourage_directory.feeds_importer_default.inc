<?php

/**
 * Implementation of hook_feeds_importer_default().
 */
function incourage_directory_feeds_importer_default() {
  $export = array();
  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'location_importer';
  $feeds_importer->config = array(
    'name' => 'Location importer',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'direct' => FALSE,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'content_type' => 'location',
        'input_format' => '0',
        'update_existing' => '2',
        'expire' => '-1',
        'mappings' => array(
          0 => array(
            'source' => 'UID',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'Official Name',
            'target' => 'field_official_name',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'Popular Name',
            'target' => 'title',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'Combined address',
            'target' => 'field_location',
            'unique' => FALSE,
          ),
        ),
        'author' => '4',
        'authorize' => 0,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => 1800,
    'expire_period' => 3600,
    'import_on_create' => TRUE,
  );

  $export['location_importer'] = $feeds_importer;
  return $export;
}
