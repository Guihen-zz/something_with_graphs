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
 #include "STACK.h"

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

int count_total_edges( link *graph_base, int graph_base_size)
{
  int i, total_edges;
  for( total_edges = 0, i = 1; i <= graph_base_size; i++)
    total_edges += count_edges( graph_base[i]);

  return total_edges;
}

void print_vertices_degree( link *graph_base, int graph_base_size)
{
  int i, j, n;
  printf( "Outdegree os vertices:\t\t\tIndegree os vertices:\n");
  for( i = 1; i <= graph_base_size; i++)
  {
    /* Outdegree: */
    printf( "\tdeg+(%3d) = %d", i, count_edges( graph_base[i]));

    printf( "\t\t\t");
    /* Indegree: */
    for( n = 0, j = 1; j <= graph_base_size; j++)
      n += search( graph_base[j], i);

    printf( "\tdeg-(%3d) = %d\n", i, n);
  }
}

void print_vertices_edge( link *graph_base, int graph_base_size)
{
  int i;
  printf( "Digraph list:\n");
  for( i = 1; i <= graph_base_size; i++)
  {
    printf( "\t(%d)", i);
    print_list( graph_base[i]);
    printf( "\n");
  }
}

int *init_distances_array( int size)
{
  int i, *d = malloc( sizeof( int) * (size + 1));
  for( i = 1; i <= size; i++) d[i] = -1;
  return d;
}

void walk_through_the_digraph( link *graph_base, int graph_base_size)
{
  int origin, destination, vertex,
      *distances, distance;
  link head, aux;

  printf( "Walking through the graph:\n");
  printf( " * What way do you want?\n");
  printf( " * Please, insert the origin vertex and the endpoint vertex: ");
  while( 1)
  {
    scanf( "%d %d", &origin, &destination);
    if( origin > graph_base_size)
    {
      printf("\tThere is no vertex with value %d.\n", origin);
      printf("\tPlease, insert a valid vertex for origin and endpoint: ");
      continue;
    }
    
    if( destination > graph_base_size)
    {
      printf("\tThere is no vertex with value %d.\n", destination);
      printf("\tPlease, insert a valid vertex for origin and endpoint: ");
      continue;
    }

    break;
  }

  distances = init_distances_array( graph_base_size);

  enqueue( origin);
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

  for( distance = 0, vertex = destination; distances[vertex] > 0; distance++)
  {
    push( vertex);
    vertex = distances[vertex];
    if (vertex == origin)
    {
      distance++; /* arrived */
      break;
    }
  }

  if( distance > 0)
  {
    printf("\tThe distance from %d to %d is %d:\n", origin, destination, distance);
    fflush( stdout);

    printf("\t(%d)", origin);
    while( !stack_empty())
    {
      printf("->(%d)", pop());
    }
    printf("\n");
  }
  else printf("\tSorry, there is no way to arrive at %d beginning in %d.\n", destination, origin);
}

void hit_a_key()
{
  printf( "(Please, hit the ENTER key to continue...)"), getchar();
  printf("\n");
}

int main( int argc, char* argv[])
{
  FILE *input;
  int vertex_from, vertex_to;
  int graph_base_size = INITIAL_GRAPH_BASE_SIZE, max;
  link *graph_base = init_graph_base( graph_base_size);

  system( "clear");

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

  printf( "######################## Graph Informations ########################\n");
  printf( "Number of vertices: %d\n", graph_base_size);
  printf( "Total edges: %d\n", count_total_edges( graph_base, graph_base_size));
  printf( "\n--------------------------"), hit_a_key();

  print_vertices_degree( graph_base, graph_base_size);
  printf( "\n--------------------------"), hit_a_key();

  print_vertices_edge( graph_base, graph_base_size);
  printf( "\n--------------------------"), hit_a_key();

  walk_through_the_digraph( graph_base, graph_base_size);
  printf( "\n\n####################################################################\n\n");
  return 0;
}
