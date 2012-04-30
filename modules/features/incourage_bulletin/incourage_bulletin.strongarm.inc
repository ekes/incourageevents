<?php

/**
 * Implementation of hook_strongarm().
 */
function incourage_bulletin_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'simplenews_content_types';
  $strongarm->value = array(
    'simplenews' => 'simplenews',
  );
  $export['simplenews_content_types'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'simplenews_vid';
  $strongarm->value = '2';
  $export['simplenews_vid'] = $strongarm;

  return $export;
}
