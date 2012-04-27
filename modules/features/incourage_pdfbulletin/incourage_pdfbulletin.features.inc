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
  return array(
    'rules' => array(
      'pdfbulletin_schedule' => array(
        '#type' => array(
          '0' => 'rule',
          '1' => 'rule',
        ),
        '#set' => array(
          '0' => 'event_node_update',
          '1' => 'event_node_update',
        ),
        '#label' => array(
          '0' => 'Schedule pdfbulletin',
          '1' => 'Schedule pdfbulletin',
        ),
        '#active' => array(
          '0' => 1,
          '1' => 1,
        ),
        '#weight' => array(
          '0' => '0',
          '1' => '0',
        ),
        '#categories' => array(
          '0' => 'pdfbulletin',
          '1' => 'pdfbulletin',
          'incourage_pdfbulletin' => 'incourage_pdfbulletin',
        ),
        '#status' => 'default',
        '#conditions' => array(
          '0' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'Created content is PDF Bulletin',
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content',
                ),
              ),
              'module' => 'Node',
            ),
            '#name' => 'rules_condition_content_is_type',
            '#settings' => array(
              'type' => array(
                'pdfbulletin' => 'pdfbulletin',
              ),
              '#argument map' => array(
                'node' => 'node',
              ),
            ),
            '#type' => 'condition',
          ),
          '1' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'Has future schedule date',
              'label callback' => FALSE,
              'arguments' => array(
                'number1' => array(
                  'label' => 'Number 1',
                  'type' => 'number',
                ),
                'number2' => array(
                  'label' => 'Number 2',
                  'type' => 'number',
                ),
              ),
              'module' => 'Rules',
            ),
            '#name' => 'rules_condition_number_compare',
            '#settings' => array(
              'number1' => '[node:field_schedule-next-timestamp]',
              'number2' => '1',
              'operation' => 'greater',
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'number1' => array(
                    '0' => 'node',
                  ),
                ),
              ),
            ),
            '#type' => 'condition',
          ),
          '2' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'Created content is PDF Bulletin',
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content',
                ),
              ),
              'module' => 'Node',
            ),
            '#name' => 'rules_condition_content_is_type',
            '#settings' => array(
              'type' => array(
                'pdfbulletin' => 'pdfbulletin',
              ),
              '#argument map' => array(
                'node' => 'node',
              ),
            ),
            '#type' => 'condition',
          ),
          '3' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'Has future schedule date',
              'label callback' => FALSE,
              'arguments' => array(
                'number1' => array(
                  'label' => 'Number 1',
                  'type' => 'number',
                ),
                'number2' => array(
                  'label' => 'Number 2',
                  'type' => 'number',
                ),
              ),
              'module' => 'Rules',
            ),
            '#name' => 'rules_condition_number_compare',
            '#settings' => array(
              'number1' => '[node:field_schedule-next-timestamp]',
              'number2' => '1',
              'operation' => 'greater',
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'number1' => array(
                    '0' => 'node',
                  ),
                ),
              ),
            ),
            '#type' => 'condition',
          ),
        ),
        '#actions' => array(
          '0' => array(
            '#type' => 'action',
            '#settings' => array(
              'task_identifier' => 'Schedule pdfbulletin [node:nid]',
              'task_date' => '[node:field_schedule-next-timestamp]',
              '#argument map' => array(
                'node' => 'node',
              ),
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'task_identifier' => array(
                    '0' => 'node',
                  ),
                  'task_date' => array(
                    '0' => 'node',
                  ),
                ),
              ),
            ),
            '#name' => 'rules_action_schedule_set_pdfbulletin_schedule_pdfbulletin',
            '#info' => array(
              'arguments' => array(
                'task_identifier' => array(
                  'type' => 'string',
                  'label' => 'Identifier',
                  'description' => 'User provided string to identify the task. Existing tasks for this rule set with the same identifier will be replaced.',
                ),
                'task_date' => array(
                  'type' => 'date',
                  'label' => 'Scheduled evaluation date',
                ),
                'node' => array(
                  'label' => 'Content',
                  'type' => 'node',
                ),
              ),
              'label' => 'Schedule "Schedule pdfbulletin"',
              'status' => 'default',
              'categories' => array(
                '0' => 'pdfbulletin',
              ),
              'module' => 'Rule Scheduler',
              'base' => 'rules_scheduler_action',
              'set' => 'pdfbulletin_schedule_pdfbulletin',
            ),
            '#weight' => 0,
          ),
          '1' => array(
            '#type' => 'action',
            '#settings' => array(
              'task_identifier' => 'Schedule pdfbulletin [node:nid]',
              'task_date' => '[node:field_schedule-next-timestamp]',
              '#argument map' => array(
                'node' => 'node',
              ),
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'task_identifier' => array(
                    '0' => 'node',
                  ),
                  'task_date' => array(
                    '0' => 'node',
                  ),
                ),
              ),
            ),
            '#name' => 'rules_action_schedule_set_pdfbulletin_schedule_pdfbulletin',
            '#info' => array(
              'arguments' => array(
                'task_identifier' => array(
                  'type' => 'string',
                  'label' => 'Identifier',
                  'description' => 'User provided string to identify the task. Existing tasks for this rule set with the same identifier will be replaced.',
                ),
                'task_date' => array(
                  'type' => 'date',
                  'label' => 'Scheduled evaluation date',
                ),
                'node' => array(
                  'label' => 'Content',
                  'type' => 'node',
                ),
              ),
              'label' => 'Schedule "Schedule pdfbulletin"',
              'status' => 'default',
              'categories' => array(
                '0' => 'pdfbulletin',
              ),
              'module' => 'Rule Scheduler',
              'base' => 'rules_scheduler_action',
              'set' => 'pdfbulletin_schedule_pdfbulletin',
            ),
            '#weight' => 0,
          ),
        ),
        '#version' => 6003,
      ),
      'pdfbulletin_schedule_new_pdfbulletin' => array(
        '#type' => array(
          '0' => 'rule',
          '1' => 'rule',
        ),
        '#set' => array(
          '0' => 'event_node_insert',
          '1' => 'event_node_insert',
        ),
        '#label' => array(
          '0' => 'Schedule pdfbulletin',
          '1' => 'Schedule pdfbulletin',
        ),
        '#active' => array(
          '0' => 1,
          '1' => 1,
        ),
        '#weight' => array(
          '0' => '0',
          '1' => '0',
        ),
        '#categories' => array(
          '0' => 'pdfbulletin',
          '1' => 'pdfbulletin',
          'incourage_pdfbulletin' => 'incourage_pdfbulletin',
        ),
        '#status' => 'default',
        '#conditions' => array(
          '0' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'Created content is PDF Bulletin',
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content',
                ),
              ),
              'module' => 'Node',
            ),
            '#name' => 'rules_condition_content_is_type',
            '#settings' => array(
              'type' => array(
                'pdfbulletin' => 'pdfbulletin',
              ),
              '#argument map' => array(
                'node' => 'node',
              ),
            ),
            '#type' => 'condition',
          ),
          '1' => array(
            '#type' => 'condition',
            '#settings' => array(
              'number1' => '[node:field_schedule-next-timestamp]',
              'number2' => '1',
              'operation' => 'greater',
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'number1' => array(
                    '0' => 'node',
                  ),
                ),
              ),
            ),
            '#name' => 'rules_condition_number_compare',
            '#info' => array(
              'label' => 'Has future schedule date',
              'label callback' => FALSE,
              'arguments' => array(
                'number1' => array(
                  'label' => 'Number 1',
                  'type' => 'number',
                ),
                'number2' => array(
                  'label' => 'Number 2',
                  'type' => 'number',
                ),
              ),
              'module' => 'Rules',
            ),
            '#weight' => 0,
          ),
          '2' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'Created content is PDF Bulletin',
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content',
                ),
              ),
              'module' => 'Node',
            ),
            '#name' => 'rules_condition_content_is_type',
            '#settings' => array(
              'type' => array(
                'pdfbulletin' => 'pdfbulletin',
              ),
              '#argument map' => array(
                'node' => 'node',
              ),
            ),
            '#type' => 'condition',
          ),
          '3' => array(
            '#type' => 'condition',
            '#settings' => array(
              'number1' => '[node:field_schedule-next-timestamp]',
              'number2' => '1',
              'operation' => 'greater',
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'number1' => array(
                    '0' => 'node',
                  ),
                ),
              ),
            ),
            '#name' => 'rules_condition_number_compare',
            '#info' => array(
              'label' => 'Has future schedule date',
              'label callback' => FALSE,
              'arguments' => array(
                'number1' => array(
                  'label' => 'Number 1',
                  'type' => 'number',
                ),
                'number2' => array(
                  'label' => 'Number 2',
                  'type' => 'number',
                ),
              ),
              'module' => 'Rules',
            ),
            '#weight' => 0,
          ),
        ),
        '#actions' => array(
          '0' => array(
            '#weight' => 0,
            '#info' => array(
              'arguments' => array(
                'task_identifier' => array(
                  'type' => 'string',
                  'label' => 'Identifier',
                  'description' => 'User provided string to identify the task. Existing tasks for this rule set with the same identifier will be replaced.',
                ),
                'task_date' => array(
                  'type' => 'date',
                  'label' => 'Scheduled evaluation date',
                ),
                'node' => array(
                  'label' => 'Content',
                  'type' => 'node',
                ),
              ),
              'label' => 'Schedule "Schedule pdfbulletin"',
              'status' => 'default',
              'categories' => array(
                '0' => 'pdfbulletin',
              ),
              'module' => 'Rule Scheduler',
              'base' => 'rules_scheduler_action',
              'set' => 'pdfbulletin_schedule_pdfbulletin',
            ),
            '#name' => 'rules_action_schedule_set_pdfbulletin_schedule_pdfbulletin',
            '#settings' => array(
              'task_identifier' => 'Schedule pdfbulletin [node:nid]',
              'task_date' => '[node:field_schedule-next-timestamp]',
              '#argument map' => array(
                'node' => 'node',
              ),
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'task_identifier' => array(
                    '0' => 'node',
                  ),
                  'task_date' => array(
                    '0' => 'node',
                  ),
                ),
              ),
            ),
            '#type' => 'action',
          ),
          '1' => array(
            '#weight' => 0,
            '#info' => array(
              'arguments' => array(
                'task_identifier' => array(
                  'type' => 'string',
                  'label' => 'Identifier',
                  'description' => 'User provided string to identify the task. Existing tasks for this rule set with the same identifier will be replaced.',
                ),
                'task_date' => array(
                  'type' => 'date',
                  'label' => 'Scheduled evaluation date',
                ),
                'node' => array(
                  'label' => 'Content',
                  'type' => 'node',
                ),
              ),
              'label' => 'Schedule "Schedule pdfbulletin"',
              'status' => 'default',
              'categories' => array(
                '0' => 'pdfbulletin',
              ),
              'module' => 'Rule Scheduler',
              'base' => 'rules_scheduler_action',
              'set' => 'pdfbulletin_schedule_pdfbulletin',
            ),
            '#name' => 'rules_action_schedule_set_pdfbulletin_schedule_pdfbulletin',
            '#settings' => array(
              'task_identifier' => 'Schedule pdfbulletin [node:nid]',
              'task_date' => '[node:field_schedule-next-timestamp]',
              '#argument map' => array(
                'node' => 'node',
              ),
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'task_identifier' => array(
                    '0' => 'node',
                  ),
                  'task_date' => array(
                    '0' => 'node',
                  ),
                ),
              ),
            ),
            '#type' => 'action',
          ),
        ),
        '#version' => 6003,
      ),
      'pdfbulletin_schedule_next' => array(
        '#type' => array(
          '0' => 'rule',
          '1' => 'rule',
        ),
        '#set' => array(
          '0' => 'pdfbulletin_schedule_pdfbulletin',
          '1' => 'pdfbulletin_schedule_pdfbulletin',
        ),
        '#label' => array(
          '0' => 'Schedule next pdfbulletin',
          '1' => 'Schedule next pdfbulletin',
        ),
        '#active' => array(
          '0' => 1,
          '1' => 1,
        ),
        '#weight' => array(
          '0' => '0',
          '1' => '0',
        ),
        '#categories' => array(
          '0' => 'pdfbulletin',
          '1' => 'pdfbulletin',
          'incourage_pdfbulletin' => 'incourage_pdfbulletin',
        ),
        '#status' => 'default',
        '#conditions' => array(
          '0' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'Has future schedule date',
              'label callback' => FALSE,
              'arguments' => array(
                'number1' => array(
                  'label' => 'Number 1',
                  'type' => 'number',
                ),
                'number2' => array(
                  'label' => 'Number 2',
                  'type' => 'number',
                ),
              ),
              'module' => 'Rules',
            ),
            '#name' => 'rules_condition_number_compare',
            '#settings' => array(
              'number1' => '[node:field_schedule-next-timestamp]',
              'number2' => '1',
              'operation' => 'greater',
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'number1' => array(
                    '0' => 'node',
                  ),
                  'number2' => array(
                    '0' => ':global',
                  ),
                ),
              ),
            ),
            '#type' => 'condition',
          ),
          '1' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'Has future schedule date',
              'label callback' => FALSE,
              'arguments' => array(
                'number1' => array(
                  'label' => 'Number 1',
                  'type' => 'number',
                ),
                'number2' => array(
                  'label' => 'Number 2',
                  'type' => 'number',
                ),
              ),
              'module' => 'Rules',
            ),
            '#name' => 'rules_condition_number_compare',
            '#settings' => array(
              'number1' => '[node:field_schedule-next-timestamp]',
              'number2' => '1',
              'operation' => 'greater',
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'number1' => array(
                    '0' => 'node',
                  ),
                  'number2' => array(
                    '0' => ':global',
                  ),
                ),
              ),
            ),
            '#type' => 'condition',
          ),
        ),
        '#actions' => array(
          '0' => array(
            '#type' => 'action',
            '#settings' => array(
              'task_identifier' => 'Schedule pdfbulletin [node:nid]',
              'task_date' => '[node:field_schedule-next-timestamp]',
              '#argument map' => array(
                'node' => 'node',
              ),
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'task_identifier' => array(
                    '0' => 'node',
                    '1' => ':global',
                  ),
                  'task_date' => array(
                    '0' => 'node',
                    '1' => ':global',
                  ),
                ),
              ),
            ),
            '#name' => 'rules_action_schedule_set_pdfbulletin_schedule_pdfbulletin',
            '#info' => array(
              'arguments' => array(
                'task_identifier' => array(
                  'type' => 'string',
                  'label' => 'Identifier',
                  'description' => 'User provided string to identify the task. Existing tasks for this rule set with the same identifier will be replaced.',
                ),
                'task_date' => array(
                  'type' => 'date',
                  'label' => 'Scheduled evaluation date',
                ),
                'node' => array(
                  'label' => 'Content',
                  'type' => 'node',
                ),
              ),
              'label' => 'Schedule "Schedule pdfbulletin"',
              'status' => 'default',
              'categories' => array(
                '0' => 'pdfbulletin',
              ),
              'module' => 'Rule Scheduler',
              'base' => 'rules_scheduler_action',
              'set' => 'pdfbulletin_schedule_pdfbulletin',
            ),
            '#weight' => 0,
          ),
          '1' => array(
            '#type' => 'action',
            '#settings' => array(
              'task_identifier' => 'Schedule pdfbulletin [node:nid]',
              'task_date' => '[node:field_schedule-next-timestamp]',
              '#argument map' => array(
                'node' => 'node',
              ),
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'task_identifier' => array(
                    '0' => 'node',
                    '1' => ':global',
                  ),
                  'task_date' => array(
                    '0' => 'node',
                    '1' => ':global',
                  ),
                ),
              ),
            ),
            '#name' => 'rules_action_schedule_set_pdfbulletin_schedule_pdfbulletin',
            '#info' => array(
              'arguments' => array(
                'task_identifier' => array(
                  'type' => 'string',
                  'label' => 'Identifier',
                  'description' => 'User provided string to identify the task. Existing tasks for this rule set with the same identifier will be replaced.',
                ),
                'task_date' => array(
                  'type' => 'date',
                  'label' => 'Scheduled evaluation date',
                ),
                'node' => array(
                  'label' => 'Content',
                  'type' => 'node',
                ),
              ),
              'label' => 'Schedule "Schedule pdfbulletin"',
              'status' => 'default',
              'categories' => array(
                '0' => 'pdfbulletin',
              ),
              'module' => 'Rule Scheduler',
              'base' => 'rules_scheduler_action',
              'set' => 'pdfbulletin_schedule_pdfbulletin',
            ),
            '#weight' => 0,
          ),
        ),
        '#version' => 6003,
      ),
      'pdfbulletin_send_pdfbulletin' => array(
        '#type' => array(
          '0' => 'rule',
          '1' => 'rule',
        ),
        '#set' => array(
          '0' => 'pdfbulletin_schedule_pdfbulletin',
          '1' => 'pdfbulletin_schedule_pdfbulletin',
        ),
        '#label' => array(
          '0' => 'Send pdfbulletin',
          '1' => 'Send pdfbulletin',
        ),
        '#active' => array(
          '0' => 1,
          '1' => 1,
        ),
        '#weight' => array(
          '0' => '-5',
          '1' => '-5',
        ),
        '#categories' => array(
          '0' => 'pdfbulletin',
          '1' => 'pdfbulletin',
          'incourage_pdfbulletin' => 'incourage_pdfbulletin',
        ),
        '#status' => 'default',
        '#conditions' => array(),
        '#actions' => array(
          '0' => array(
            '#type' => 'action',
            '#settings' => array(
              '#argument map' => array(
                'node' => 'node',
              ),
            ),
            '#name' => 'pdfbulletin_send_action',
            '#info' => array(
              'label' => 'Send a PDF bulletin',
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'PDF Bulletin to send',
                ),
              ),
              'module' => 'PDF Bulletin',
            ),
            '#weight' => 0,
          ),
          '1' => array(
            '#type' => 'action',
            '#settings' => array(
              '#argument map' => array(
                'node' => 'node',
              ),
            ),
            '#name' => 'pdfbulletin_send_action',
            '#info' => array(
              'label' => 'Send a PDF bulletin',
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'PDF Bulletin to send',
                ),
              ),
              'module' => 'PDF Bulletin',
            ),
            '#weight' => 0,
          ),
        ),
        '#version' => 6003,
      ),
    ),
    'rule_sets' => array(
      'pdfbulletin_schedule_pdfbulletin' => array(
        'arguments' => array(
          'node' => array(
            'label' => array(
              '0' => 'Content',
              '1' => 'Content',
            ),
            'type' => array(
              '0' => 'node',
              '1' => 'node',
            ),
          ),
        ),
        'label' => array(
          '0' => 'Schedule pdfbulletin',
          '1' => 'Schedule pdfbulletin',
        ),
        'status' => 'default',
        'categories' => array(
          '0' => 'pdfbulletin',
          '1' => 'pdfbulletin',
          'incourage_pdfbulletin' => 'incourage_pdfbulletin',
        ),
      ),
    ),
  );
}

/**
 * Implementation of hook_views_api().
 */
function incourage_pdfbulletin_views_api() {
  return array(
    'api' => '2',
  );
}
