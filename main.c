/******************************************************************************\
 * Graphs - EP2 - MAC0323
 *
 * Author: GUILHERME HENRIQUE ROJAS V. DE LIMA
 * email: guihen@linux.ime.usp.br
 *
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "LIST.h"
#include "QUEUE.h"

#define INITIAL_GRAPH_BASE_SIZE 1

link *init_graph_base( int size)
{
  int i;
  link *l = malloc( sizeof( link) * (size + 1));
  for (i = 1; i <= size; i++)
    l[i] = init_link();
  return l;
}

link *rezise_graph_base( link *graph_base, int graph_base_size, int new_size)
{
  link *gb = malloc( sizeof( link) * (new_size + 1));
  int i;
  for( i = 1; i <= graph_base_size; i++)
  {
    gb[i] = graph_base[i];
    graph_base[i] = NULL;
  }
  /* i := the first index that doesn't belong to the previous graph base. */
  while( i <= new_size)
    gb[i++] = init_link();

  free( graph_base);
  return gb;
}



int main( int argc, char* argv[])
{
  FILE *input;
  int vertex_from, vertex_to, i;
  int graph_base_size = INITIAL_GRAPH_BASE_SIZE, max;
  int *distances, distance, vertex;
  link aux, head;
  link *graph_base = init_graph_base( graph_base_size);

  if( argc != 2)
  {
    fprintf( stderr, "Error: Wrong number of params. ");
    fprintf( stderr, "Please, use ./main <FILE_INPUT_NAME>\n");
    return 1;
  }

  input = fopen( argv[1], "r");
  if (!input)
  {
    fprintf( stderr, "Error: Cannot open the file.\n");
    return 2; 
  }

  while( fscanf( input, "%d %d", &vertex_from, &vertex_to) != EOF)
  {
    max = vertex_from > vertex_to ? vertex_from : vertex_to;
    if( max > graph_base_size)
    {
      graph_base = rezise_graph_base( graph_base, graph_base_size, max);
      graph_base_size = max;
    }

    new_edge( graph_base[vertex_from], vertex_to);
  }

  distances = malloc( sizeof( int) * graph_base_size + 1);
  for( i = 1; i <= graph_base_size; i++)
    distances[i] = -1;

  enqueue( 6);
  distances[6] = 0;
  while( !queue_empty())
  {
    vertex = dequeue();
    head = graph_base[vertex];
    for( aux = head->next; aux != head; aux = aux->next)
    {
      if( distances[aux->index] == -1)
      {
        distances[aux->index] = vertex;
        enqueue( aux->index);
      }
    }
  }

  distance = distances[1];
  while( distance > 0)
  {
    printf("%d\n", distance);
    distance = distances[distance];
  }
  
  printf("Terminou\n");

  return 0;
}
