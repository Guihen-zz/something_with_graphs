#ifndef QUEUE
#define QUEUE

/******************************************************************************\
 * Graphs - EP2 - MAC0323
 *
 * Author: GUILHERME HENRIQUE ROJAS V. DE LIMA
 * email: guihen@linux.ime.usp.br
 *
 ******************************************************************************/

 #include "LIST.h"

typedef struct content *queue;
struct content
{
  link node;
  queue next;
};

void enqueue( link);
link dequeue( void);

#endif
