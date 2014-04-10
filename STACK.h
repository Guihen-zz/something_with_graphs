#ifndef STACK
#define STACK

/******************************************************************************\
 * Graphs - EP2 - MAC0323
 *
 * Author: GUILHERME HENRIQUE ROJAS V. DE LIMA
 * email: guihen@linux.ime.usp.br
 *
 ******************************************************************************/

 #include <stdbool.h>
 #include "LIST.h"

typedef struct c *stack;
struct c
{
  int vertex;
  stack next;
};

void push( int vertex_index);
int pop( void);
bool stack_empty(void);

#endif
