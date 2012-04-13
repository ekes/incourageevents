<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function incourage_pdfbulletin_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "openlayers" && $api == "openlayers_presets") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_rules_defaults().
 */
function incourage_pdfbulletin_rules_defaults() {
  return array();
}

/**
 * Implementation of hook_views_api().
 */
function incourage_pdfbulletin_views_api() {
  return array(
    'api' => '2',
  );
}
