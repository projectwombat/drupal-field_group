<?php

/*
 * @file
 * Helper functions for the fieldgroup module.
 */

/**
 * Calculates html classes for a group.
 */
function _field_group_get_html_classes(&$group) {

  if (isset($group->format_settings['formatter'])) {
    $group->collapsible = in_array($group->format_settings['formatter'], array('collapsible', 'collapsed'));
    // Open or closed horizontal or vertical tabs will be collapsible by default.
    if ($group->format_type == 'tab' || $group->format_type == 'htab') {
      $group->collapsible = TRUE;
    }
    $group->collapsed = in_array($group->format_settings['formatter'], array('collapsed', 'closed'));
  }

  $classes = new stdClass();

  // Prepare extra classes, required and optional ones.
  $optional = array(str_replace('_', '-', $group->group_name));
  $required = array();
  if ($group->format_type == 'multipage') {
    $required[] = 'field-group-' . $group->format_type;
  }
  else {
    $optional[] = 'field-group-' . $group->format_type;
  }

  if (isset($group->format_settings['formatter']) && $group->collapsible) {
    $required[] = 'collapsible';
    if ($group->collapsed) {
      $required[] = 'collapsed';
    }
  }

  if (isset($group->format_settings['instance_settings'])) {

    // Add a required-fields class to trigger the js.
    if (!empty($group->format_settings['instance_settings']['required_fields'])) {
      $required[] = 'required-fields';
    }

    // Add user selected classes.
    if (!empty($group->format_settings['instance_settings']['classes'])) {
      $required[] = check_plain($group->format_settings['instance_settings']['classes']);
    }

    // Extra required classes for div.
    if ($group->format_type == 'div') {
      if ($group->format_settings['formatter'] != 'open') {

        $speed = isset($group->format_settings['instance_settings']['speed']) ? $group->format_settings['instance_settings']['speed'] : 'none';
        $required[] = 'speed-' . $speed;

        $effect = isset($group->format_settings['instance_settings']['effect']) ? $group->format_settings['instance_settings']['effect'] : 'none';
        $required[] = 'effect-' . $effect;
      }
    }

    // Extra required classes for accordions.
    elseif ($group->format_type == 'accordion') {
      $required[] = 'field-group-' . $group->format_type . '-wrapper';
      $effect = isset($group->format_settings['instance_settings']['effect']) ? $group->format_settings['instance_settings']['effect'] : 'none';
      $required[] = 'effect-' . $effect;
    }

  }

  $classes->required = $required;
  $classes->optional = $optional;

  return $classes;
}

/**
 * Get the default formatter settings for a given formatter and a mode.
 */
function _field_group_get_default_formatter_settings($format_type, $context) {

  $field_group_types = field_group_formatter_info();
  $formatter = $field_group_types[$context][$format_type];

  return array(
    'formatter' => isset($formatter['default_formatter']) ? $formatter['default_formatter'] : '',
    'instance_settings' => $formatter['instance_settings']
  );
}

/**
 * Get the config filename for a given group.
 */
function _field_group_get_config_name($group) {
  return 'field_group.' . $group->entity_type . '.' . $group->bundle . '.' . $group->context . '.' . $group->mode . '.' . $group->group_name;
}