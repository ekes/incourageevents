<?php

/**
 * Implementation of hook_feeds_importer_default().
 */
function incourage_events_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'ical';
  $feeds_importer->config = array(
    'name' => 'iCal importer',
    'description' => 'Event, calendar, importer',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
      ),
    ),
    'parser' => array(
      'plugin_key' => 'ParserIcalFeedsParser',
      'config' => array(),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'content_type' => 'event',
        'input_format' => '0',
        'update_existing' => '2',
        'expire' => '-1',
        'mappings' => array(
          0 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'description',
            'target' => 'body',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'ical_date',
            'target' => 'field_date:start',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'url',
            'target' => 'url',
            'unique' => 0,
          ),
          4 => array(
            'source' => 'guid',
            'target' => 'guid',
            'unique' => 1,
          ),
          5 => array(
            'source' => 'parent:taxonomy:1',
            'target' => 'taxonomy:1',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'tags',
            'target' => 'taxonomy:1',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'ical_location',
            'target' => 'field_location',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'ical_location',
            'target' => 'field_location_reference:first',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'ical_location',
            'target' => 'field_organiser_reference:last',
            'unique' => FALSE,
          ),
        ),
        'author' => 0,
        'authorize' => 0,
      ),
    ),
    'content_type' => 'event_feed',
    'update' => 0,
    'import_period' => '1800',
    'expire_period' => 3600,
    'import_on_create' => 1,
  );
  $export['ical'] = $feeds_importer;

  return $export;
}
