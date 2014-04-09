#ifndef QUEUE
#define QUEUE

/******************************************************************************\
 * Graphs - EP2 - MAC0323
 *
 * Author: GUILHERME HENRIQUE ROJAS V. DE LIMA
 * email: guihen@linux.ime.usp.br
 *
 ******************************************************************************/

 #include <stdbool.h>
 #include "LIST.h"

typedef struct content *queue;
struct content
{
  int vertex;
  queue next;
};

void enqueue( int vertex_index);
int dequeue( void);
bool queue_empty(void);

#endif
