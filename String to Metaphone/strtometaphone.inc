<?php
// $Id: strtometaphone.inc,v 0.1 2013/03/09  StephenOTT

$plugin = array(
  'form' => 'feeds_tamper_strtometaphone_form',
  'callback' => 'feeds_tamper_strtometaphone_callback',
  'description' => 'feeds_tamper_strtometaphone_description',
  'machine_name' => 'feeds_tamper_strtometaphone_machine_name',
  'name' => 'Calculate metaphone of string',
  'multi' => 'loop',
  'category' => 'Text',
);

function feeds_tamper_strtometaphone_form($importer, $element_key, $settings) {
  $form = array();
  $form['html'] = array(
    '#markup' => t('Similar to soundex metaphone creates the same key for similar sounding words Its more accurate than soundex() as it knows the basic rules of English pronunciation. The metaphone generated keys are of variable length.')
  );
  
   $form['phonemesRestrictCount'] = array(
    '#type' => 'textfield',
    '#title' => t('Phonemes character limit'),
    '#default_value' => isset($settings['phonemesRestrictCount']) ? $settings['phonemesRestrictCount'] : '',
    '#description' => t('Parameter that restricts the returned metaphone key to phonemes characters in length.  0 or no value means no restriction'),
  );
  
  
  return $form;
}

function feeds_tamper_strtometaphone_description($settings) {
  return 'Calculate metaphone of string';
}

function feeds_tamper_strtometaphone_machine_name($settings) {
  return 'strtometaphone';
}

function feeds_tamper_strtometaphone_callback($source, $item_key, $element_key, &$field, $settings) {
  if (!empty($settings['phonemesRestrictCount'])) {
    $field = metaphone($field, $settings['phonemesRestrictCount']);
  }
  else {
    $field = metaphone($field);
  }
}
 
?>