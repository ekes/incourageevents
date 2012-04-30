<?php

/**
 * Implementation of hook_user_default_roles().
 */
function incourage_bulletin_user_default_roles() {
  $roles = array();

  // Exported role: bulletin administrator
  $roles['bulletin administrator'] = array(
    'name' => 'bulletin administrator',
  );

  return $roles;
}
