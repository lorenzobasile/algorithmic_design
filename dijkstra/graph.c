#include "graph.h"

int in(ll list, int index){
    ll temp=list;
    while(temp!=NULL){
        if(temp->node==index) return 1;
        temp=temp->next;
    }
    return 0;
}

void graph_random_init(graph* G, const size_t size, const unsigned int max_cost, const unsigned int num_of_neighbours){
    G->size = size;
    G->adj = malloc(sizeof(ll)*G->size);
    for(int i=0; i<G->size; i++){
        G->adj[i]=NULL;
        ll temp;
        for(int j=0; j<num_of_neighbours; j++){
            temp=malloc(sizeof(listnode));
            int candidate;
            do{
                candidate=rand()%G->size;
            } while(candidate==i || in(G->adj[i], candidate));
            temp->node=candidate;
            temp->cost=rand()%max_cost;
            temp->next=G->adj[i];
            G->adj[i]=temp;
        }
        temp=G->adj[i];
        /*while(temp!=NULL){
            printf("%d -> %d, cost: %d \n", i, temp->node, temp->cost);
            temp=temp->next;
        }*/
    }
}

void deallocate_graph(graph* G){
    listnode* temp,*temp2;
    for(int i=0; i<G->size; i++){
        temp=G->adj[i];
        while(temp!=NULL){
            temp2=temp;
            temp=temp->next;
            free(temp2);
        }
    }
    free(G->adj);
}
