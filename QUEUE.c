/******************************************************************************\
 * Graphs - EP2 - MAC0323
 *
 * Author: GUILHERME HENRIQUE ROJAS V. DE LIMA
 * email: guihen@linux.ime.usp.br
 *
 ******************************************************************************/

#include <stdlib.h>
#include "QUEUE.h"

static queue Queue = NULL;

void enqueue( link node)
{
  queue new = malloc( sizeof( *new));
  queue aux;
  
  if( Queue == NULL)
  {
    Queue = malloc( sizeof( *Queue));
    Queue->next = Queue;
  }

  for( aux = Queue->next; aux->next != Queue; aux = aux->next);
  
  new->node = node;
  new->next = aux->next;
  aux->next = new;
}

link dequeue()
{
  queue node = Queue->next;
  link l;
  if( node == Queue) return NULL;
  
  l = node->node;
  Queue->next = node->next;
  free( node);

  return l;
}
