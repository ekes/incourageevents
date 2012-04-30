<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function incourage_bulletin_user_default_permissions() {
  $permissions = array();

  // Exported permission: administer newsletters
  $permissions['administer newsletters'] = array(
    'name' => 'administer newsletters',
    'roles' => array(
      '0' => 'bulletin administrator',
      '1' => 'technical administrator',
    ),
  );

  // Exported permission: administer simplenews settings
  $permissions['administer simplenews settings'] = array(
    'name' => 'administer simplenews settings',
    'roles' => array(
      '0' => 'technical administrator',
    ),
  );

  // Exported permission: administer simplenews subscriptions
  $permissions['administer simplenews subscriptions'] = array(
    'name' => 'administer simplenews subscriptions',
    'roles' => array(
      '0' => 'bulletin administrator',
      '1' => 'technical administrator',
    ),
  );

  // Exported permission: send newsletter
  $permissions['send newsletter'] = array(
    'name' => 'send newsletter',
    'roles' => array(
      '0' => 'bulletin administrator',
      '1' => 'technical administrator',
    ),
  );

  // Exported permission: subscribe to newsletters
  $permissions['subscribe to newsletters'] = array(
    'name' => 'subscribe to newsletters',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
      '2' => 'technical administrator',
    ),
  );

  return $permissions;
}
