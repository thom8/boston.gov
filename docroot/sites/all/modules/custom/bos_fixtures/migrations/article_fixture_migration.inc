<?php
/**
 * @file
 * Contains ArticleFixtureMigration class.
 */

/**
 * Class ArticleFixtureMigration.
 */
class ArticleFixtureMigration extends NodeBaseMigration {

  /**
   * Constructor for article fixture migration.
   *
   * @param array $arguments
   *   Migration arguments.
   */
  public function __construct($arguments = array()) {
    parent::__construct($arguments);
    $this->description = 'Migration class for Article page fixtures.';

    $this->addFieldMapping('title', 'title')
      ->xpath('title');
    $this->addFieldMapping('body', 'body')
      ->xpath('body');
    $this->addFieldMapping('uid', 'author')
      ->xpath('author')
      ->sourceMigration($arguments['field_migrations']['uid'])
      ->defaultValue(1);
    $this->addFieldMapping('field_intro_text', 'intro_text')
      ->xpath('intro_text');
  }

  /**
   * Specify what fields are available to the XML mapping.
   *
   * @return array
   *   The fields that this XML migration contains.
   */
  protected function getFields() {
    return array(
      'id' => t('User ID'),
      'author' => t('Author'),
      'title' => t('Title'),
      'body' => t('Body'),
      'intro_text' => t('Intro Text'),
    );
  }

  /**
   * Get the node migration's type/bundle.
   *
   * @return string
   *   The machine name of the node type/bundle.
   */
  protected function getNodeType() {
    return 'article';
  }

}
