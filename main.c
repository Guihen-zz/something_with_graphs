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

link *init_graph_base( int size)
{
  int i;
  link *l = malloc( sizeof( link) * size);
  for (i = 0; i < 100; i++)
    l[i] = init_link();
  return l;
}

int main( int argc, char* argv[])
{
  FILE *input;
  int vertex_from, vertex_to, i;
  link *graph_base = init_graph_base( 100);

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
    new_edge( graph_base[vertex_from], vertex_to);
  }

  printf("Terminou\n");

  return 0;
}
