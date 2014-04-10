/******************************************************************************\
 * Graphs - EP2 - MAC0323
 *
 * Author: GUILHERME HENRIQUE ROJAS V. DE LIMA
 * email: guihen@linux.ime.usp.br
 *
 ******************************************************************************/

#include <stdlib.h>
#include "LIST.h"

/* link to a circular list. */
link init_link()
{
  link l = malloc( sizeof( link *));
  l->next = l;
  return l;
}

void insert( link head, link vertex_to)
{
  int index = vertex_to->index;
  link aux; /* aux point to the cel will be the vertex_to */
  for( head->index = index, aux = head; aux->next->index < index; aux = aux->next);

  vertex_to->next = aux->next;
  aux->next = vertex_to;
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

int count_edges( link head)
{
  int n;
  link aux = head->next;
  for( n = 0; aux != head; aux = aux->next) {
    n++;
  }
  return n;
}

int search( link head, int vertex)
{
  link aux;
  head->index = vertex;
  for( aux = head->next; vertex != aux->index; aux = aux->next);
  return aux != head;
}
