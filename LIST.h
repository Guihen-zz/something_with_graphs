#ifndef LIST
#define LIST

/******************************************************************************\
 * Graphs - EP2 - MAC0323
 *
 * Author: GUILHERME HENRIQUE ROJAS V. DE LIMA
 * email: guihen@linux.ime.usp.br
 *
 ******************************************************************************/

typedef struct node *link;
struct node
{
  int index;
  link next;
};

void new_edge( link vertex_from, int vertex_to);
link init_link( void);
int count_edges( link head);

#endif
