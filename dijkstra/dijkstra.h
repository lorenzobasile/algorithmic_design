#ifndef _dijkstra

#define _dijkstra
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include "binheap.h"
#include "graph.h"

#define MAX_VAL INT_MAX

//initialization function: taken an array of distances d and an array of predecessors p, sets all distances
//to MAX_VAL and all predecessors to -1
void init_sssp(int* d, int* p, size_t size);

//relax function for 
void relax(int* d, int* p, int u, int v, int w);
void dijkstra(graph G, int* distances, int* pred, int s);
void update_distance(int* d, int v, int new_val);
int extractmin(int* Q, int* d, size_t* queue_size);
int isempty(size_t queue_size);
void swap(int* array, int i, int j);

void relax_heap(binheap_type* h, int*d, int* p, int u, int v, int w);
void dijkstra_heap(graph G, int* distances, int* pred, int s);

#endif
