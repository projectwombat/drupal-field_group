<?php
/**
 * @file
 * Contains \Drupal\field_group\Plugin\Core\Entity\FieldGroup.
 */

namespace Drupal\field_group\Plugin\Core\Entity;

use Drupal\Core\Config\Entity\ConfigEntityBase;
use Drupal\Core\Entity\Annotation\EntityType;
use Drupal\Core\Annotation\Translation;
use Drupal\field_group\FieldGroupInterface;

/**
 * Defines a FieldGroup configuration entity.
 *
 * @EntityType(
 *   id = "field_group",
 *   label = @Translation("Field Group data object"),
 *   controllers = {
 *     "storage" = "Drupal\Core\Config\Entity\ConfigStorageController"
 *   },
 *   entity_keys = {
 *     "id" = "id",
 *     "label" = "label",
 *     "uuid" = "uuid"
 *   },
 *   config_prefix = "field_group"
 * )
 */
class FieldGroup extends ConfigEntityBase implements FieldGroupInterface {

  /**
   * The machine-readable ID for the configurable.
   */
  public $id;

  /**
   * The human-readable label for the configurable.
   */
  public $label;

  /**
   * The universal unique identifier for the configurable.
   */
  public $uuid;


  public $entity_type;
  public $bundle;
  public $mode;
  public $widget_type;
  public $parent;

  public $machine_name;
  public $fields;

  public $field_order;
  public $field_groups;

  // Override methods from ConfigEntityBase as needed.

  public function getSettings() {
    // return $this->settings;
  }

}
