#include "dijkstra.h"
#include <stdio.h>

#define MAX_VAL 2048

void init_sssp(graph G){
    for(int i=0; i<G.size; i++){
        G.V[i].d=MAX_VAL;
        G.V[i].pred=-1;
    }
}
void relax(nodearray Q, int u, int v, int w, size_t queue_size){
    if(Q[u].d+w<Q[v].d){
        update_distance(Q,v,Q[u].d+w, queue_size);
        Q[v].pred=Q[u].name;
    }
}

void update_distance(nodearray Q, int v, int new_val, size_t queue_size){
    Q[v].d=new_val;
}

nodearray build_queue(graph G){
    nodearray queue=G.V;
    return queue;
}

int extract_min(nodearray Q, size_t* queue_size){
    int argmin;
    int min=MAX_VAL;
    for(int i=0; i<*queue_size; i++){
        if(Q[i].d<min){
            argmin=i;
        }
    }
    swap(Q,argmin,*queue_size-1);
    (*queue_size)--;
    return *queue_size;
}

void dijkstra(graph G, int s){
    init_sssp(G);
    G.V[s].d=0;
    G.V[s].pred=0;
    nodearray queue=build_queue(G);
    size_t queue_size=G.size;
    while(queue_size>0){
        int u=extract_min(queue, &queue_size);
        for(int i=0; i<queue_size; i++){
            if(G.adj[queue[u].name][queue[i].name]>0){
                relax(queue, u, i, G.adj[queue[u].name][queue[i].name], queue_size);
            }
        }
    }
}
void swap(nodearray array, int i, int j){
    node temp;
    memcpy(&temp, &array[i], sizeof(node));
    memcpy(&array[i], &array[j], sizeof(node));
    memcpy(&array[j], &temp, sizeof(node));
}
int isempty(size_t queue_size){
    return queue_size==0;
}
void print_node(node n){
    printf("%d, %d, %d \n", n.d, n.pred, n.name);
}
