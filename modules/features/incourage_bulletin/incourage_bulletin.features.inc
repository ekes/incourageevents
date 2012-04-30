<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function incourage_bulletin_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function incourage_bulletin_node_info() {
  $items = array(
    'simplenews' => array(
      'name' => t('Newsletter issue'),
      'module' => 'features',
      'description' => t('A newsletter issue to be sent to subscribed email addresses.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Body'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}
