/******************************************************************************\
 * Graphs - EP2 - MAC0323
 *
 * Author: GUILHERME HENRIQUE ROJAS V. DE LIMA
 * email: guihen@linux.ime.usp.br
 *
 ******************************************************************************/

#include <stdlib.h>
#include "LIST.h"

void insert( link vertex_from, link vertex_to)
{
  link node = vertex_from;
  int index = vertex_to->index;
  while( node->next != NULL && node->next->index < index)
    node = node->next;

  vertex_to->next = node->next;
  node->next = vertex_to;
}

link new_link( int vertex)
{
  link l = malloc( sizeof( *l));
  l->index = vertex;
  l->next = NULL;
  return l;
}

void new_edge( link vertex_from, int vertex_to)
{
  link l = new_link( vertex_to);
  insert( vertex_from, l);
}
