<?php

use Drupal\node\Entity\Node;
use Drupal\image\Entity\ImageStyle;

/**
 * @file
 * Theme for GALERIA views.
 */
function template_preprocess_views_view_galeria(&$variables) {
  // View options set by user.
  $options = $variables['view']->style_plugin->options;

  $nodos = [];
  $etiquetasGenerales = [];
  $count = 0;


  foreach ($variables['view']->result as $id => $result) {
    $etiquetas = [];
    $imagenes = [];
    $imageStyle = ImageStyle::load('large');

    // Cagamos el nodo
    $node = Node::load($result->nid);

    // Insertamos el titulo, el body y la url
    $nodos[$count]['id'] = $result->nid;
    $nodos[$count]['titulo'] = $node->getTitle();
    $nodos[$count]['body'] = $node->get('body')->value;
    $nodos[$count]['url'] = $node->toUrl()->setAbsolute()->toString();

    // Insertamos los campos de las imagenes
    // Primero la imagen por defecto.
    if ($node->hasField('field_image')) {
      $imagenes[0]['alt'] = $node->get('field_image')->getValue()[0]['alt'];
      $imagenes[0]['urlImagenOriginal'] = file_create_url($node->field_image->entity->getFileUri());
      $imagenes[0]['urlImagenLarge'] = $imageStyle->buildUrl($node->field_image->entity->getFileUri());
    }
    if ($node->hasField('field_imagenes')) {
      foreach ($node->field_imagenes as $key => $imagen) {
        $i = $key + 1;
        $imagenes[$i]['alt'] = $imagen->get('alt')->getValue();
        $imagenes[$i]['urlImagenOriginal'] = file_create_url($imagen->entity->getFileUri());
        $imagenes[$i]['urlImagenLarge'] = $imageStyle->buildUrl($imagen->entity->getFileUri());
      }
    }
    $nodos[$count]['imagenes'] = $imagenes;

    // Ahora las etiquetas
    if ($node->hasField('field_tags')) {
      foreach ($node->field_tags->referencedEntities() as $key => $term) {
        $etiqueta = $term->getName();
      $etiquetas[$key] = $etiqueta;
        // insertamos la etiqueta en etiquetas generales.
        if (!in_array($etiqueta, $etiquetasGenerales)) {
          $etiquetasGenerales[$term->id()] = $etiqueta;
        }
      }
    }
    $nodos[$count]['etiquetas'] = $etiquetas;



    $count++;
  }
//  kint($variables['view']->getPath());

  
  
  $options['etiquetasGenerales'] = $etiquetasGenerales;
  $options['nodos'] = $nodos;
 
  // añadimos los nodos a javascript;
  $variables['#attached']['drupalSettings']['galeria']['nodos'] = $nodos;
  // Update options for twig. 
  $variables['options'] = $options;
}
