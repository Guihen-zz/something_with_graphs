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

void enqueue( int index)
{
  queue new = malloc( sizeof( *new));
  queue aux;
  
  if( Queue == NULL)
  {
    Queue = malloc( sizeof( *Queue));
    Queue->next = Queue;
  }

  for( aux = Queue->next; aux->next != Queue; aux = aux->next);
  
  new->vertex = index;
  new->next = aux->next;
  aux->next = new;
}

int dequeue()
{
  queue node = Queue->next;
  int l;
  if( node == Queue) return -1;
  
  l = node->vertex;
  Queue->next = node->next;
  free( node);

  return l;
}

bool queue_empty()
{
  return Queue->next == Queue;
}
