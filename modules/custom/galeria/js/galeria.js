/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


$('#myModal').on('show.bs.modal', function (event) {
  
  var button = $(event.relatedTarget); 
  var nodoId = button.data('nodoid'); 
  // cogemos los datos del nodo de drupalSettings
  var nodo = drupalSettings.galeria.nodos.filter(x => x.id == nodoId)[0]; 
  
  console.log(nodo);
  console.log(nodo.titulo);
  
  // Creamos la imagen
  var img = $('<img/>')
    .attr("src", nodo.imagenes[0].urlImagenOriginal)
    .attr("alt", nodo.imagenes[0].alt)
    .addClass("img-responsive");
    
  
  var modal = $(this);
  modal.find('.modal-title').text(nodo.titulo);
  modal.find('.modal-body').html($('<img/>')
    .attr("src", nodo.imagenes[0].urlImagenOriginal)
    .attr("alt", nodo.imagenes[0].alt)
    .addClass("img-responsive"));
//  modal.find('.modal-title').text(titulo);
//  modal.find('.modal-title').text(titulo);


//modal.removeData('bs.modal');
});