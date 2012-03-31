<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function incourage_directory_user_default_permissions() {
  $permissions = array();

  // Exported permission: clear location_importer feeds
  $permissions['clear location_importer feeds'] = array(
    'name' => 'clear location_importer feeds',
    'roles' => array(),
  );

  // Exported permission: create location content
  $permissions['create location content'] = array(
    'name' => 'create location content',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: delete any location content
  $permissions['delete any location content'] = array(
    'name' => 'delete any location content',
    'roles' => array(
      '0' => 'bulletin administrator',
    ),
  );

  // Exported permission: delete own location content
  $permissions['delete own location content'] = array(
    'name' => 'delete own location content',
    'roles' => array(
      '0' => 'bulletin administrator',
    ),
  );

  // Exported permission: edit any location content
  $permissions['edit any location content'] = array(
    'name' => 'edit any location content',
    'roles' => array(
      '0' => 'bulletin administrator',
    ),
  );

  // Exported permission: edit own location content
  $permissions['edit own location content'] = array(
    'name' => 'edit own location content',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  // Exported permission: import location_importer feeds
  $permissions['import location_importer feeds'] = array(
    'name' => 'import location_importer feeds',
    'roles' => array(),
  );

  return $permissions;
}
