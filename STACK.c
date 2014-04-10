/******************************************************************************\
 * Graphs - EP2 - MAC0323
 *
 * Author: GUILHERME HENRIQUE ROJAS V. DE LIMA
 * email: guihen@linux.ime.usp.br
 *
 ******************************************************************************/

#include <stdlib.h>
#include "STACK.h"

static stack Stack = NULL;

void push( int index)
{
  stack new = malloc( sizeof( *new));
  new->vertex = index;

  if( Stack == NULL)
  {
    Stack = malloc( sizeof( *Stack));
    Stack->next = Stack;
  }

  new->next = Stack->next;
  Stack->next = new;
}

int pop()
{
  stack node = Stack->next;
  int l;
  if( node == Stack) return -1;
  
  l = node->vertex;
  Stack->next = node->next;
  free( node);

  return l;
}

bool stack_empty()
{
  return Stack->next == Stack;
}
