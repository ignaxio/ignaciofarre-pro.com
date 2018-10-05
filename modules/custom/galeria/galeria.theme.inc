<?php

use Drupal\node\Entity\Node;
use Drupal\image\Entity\ImageStyle;

/**
 * @file
 * Theme for GALERIA views.
 */
function template_preprocess_views_view_galeria(&$variables) {
  // View options set by user.
//  dump($variables);
  $options = $variables['view']->style_plugin->options;

  $nodos = [];
  $etiquetasGenerales = [];
  $count = 0;

  foreach ($variables['view']->result as $id => $result) {
    $etiquetas = [];
    $imagenes = [];
    
    // Cagamos el nodo
    $node = Node::load($result->nid);

    // Insertamos el titulo, el body y la url
    $nodos[$count]['id'] = $result->nid;
    $nodos[$count]['titulo'] = $node->getTitle();
    $nodos[$count]['body'] = $node->get('body')->value;
    $nodos[$count]['url'] = $node->toUrl()->setAbsolute()->toString();

    if (isset($node->field_imagen_principal->entity)) {
      // generamos los el estilo de imagen
      $style = ImageStyle::load('imagen_cuadrada_para_galeria_300');
      $image_uri = $node->field_imagen_principal->entity->field_media_image_1->entity->getFileUri();
      $destination = $style->buildUri($image_uri);
      $style->createDerivative($image_uri, $destination);

      $imagenes[0]['alt'] = $node->field_imagen_principal->entity->field_media_image_1->alt;
      $imagenes[0]['urlImagenLarge'] = file_create_url($destination);
      
      $nodos[$count]['imagenes'] = $imagenes;
    }
    
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

  $options['etiquetasGenerales'] = $etiquetasGenerales;
  $options['nodos'] = $nodos;

  // añadimos los nodos a javascript;
  $variables['#attached']['drupalSettings']['galeria']['nodos'] = $nodos;
  // Update options for twig. 
  $variables['options'] = $options;
}
