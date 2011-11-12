<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function incourage_pdfbulletin_user_default_permissions() {
  $permissions = array();

  // Exported permission: administer pdf bulletins
  $permissions['administer pdf bulletins'] = array(
    'name' => 'administer pdf bulletins',
    'roles' => array(
      '0' => 'technical administrator',
    ),
  );

  // Exported permission: create pdf bulletins
  $permissions['create pdf bulletins'] = array(
    'name' => 'create pdf bulletins',
    'roles' => array(
      '0' => 'bulletin administrator',
      '1' => 'technical administrator',
    ),
  );

  // Exported permission: delete any pdf bulletins
  $permissions['delete any pdf bulletins'] = array(
    'name' => 'delete any pdf bulletins',
    'roles' => array(
      '0' => 'bulletin administrator',
      '1' => 'technical administrator',
    ),
  );

  // Exported permission: delete own pdf bulletins
  $permissions['delete own pdf bulletins'] = array(
    'name' => 'delete own pdf bulletins',
    'roles' => array(
      '0' => 'bulletin administrator',
      '1' => 'technical administrator',
    ),
  );

  // Exported permission: edit any pdf bulletins
  $permissions['edit any pdf bulletins'] = array(
    'name' => 'edit any pdf bulletins',
    'roles' => array(
      '0' => 'bulletin administrator',
      '1' => 'technical administrator',
    ),
  );

  // Exported permission: edit own pdf bulletins
  $permissions['edit own pdf bulletins'] = array(
    'name' => 'edit own pdf bulletins',
    'roles' => array(
      '0' => 'bulletin administrator',
      '1' => 'technical administrator',
    ),
  );

  return $permissions;
}
