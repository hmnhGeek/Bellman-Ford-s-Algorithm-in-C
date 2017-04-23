// Bellman-Ford's Algorithm Implementation in C. //
#include<stdio.h>
#include<stdlib.h>
#define INF 32767

// define an edge datatype. //
typedef struct edge_node{
    int src, dest, weight;
}edge;

// define a graph datatype. //
typedef struct graph_node{
    int V, E;
    struct edge_node *next;
}Graph;

// Create a utility function to create a graph. //
Graph *create(int V, int E){
    Graph *graph = (Graph *)malloc(sizeof(Graph));

    graph -> V = V;
    graph -> E = E;
    graph -> next = (edge *)malloc(graph -> E *sizeof(edge));

    return graph;
}

// Now create the function bellmanFord() to implement the algorithm. //
void bellmanFord(Graph *graph, int source){
    int V = graph -> V;
    int E = graph -> E;

    int dist[V];

    // Initialise the distances of the vertices of the graph. //
    int i = 1;
    for(i; i<V; i+=1){
        dist[i] = INF;
    }

    // Set the distance of source as 0. //
    dist[source] = 0;

    // Now iterate through the graph. //
    int j = 0;

    for(j; j< V; j+=1){
        int e = 0;
        for(e; e<E; e+=1){
            int u = graph -> next[e].src;
            int v = graph -> next[e].dest;
            int w = graph -> next[e].weight;

            if(dist[u] != INF && dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
            }
        }
    }

    // Now iterate one more time to check for negative cycle. //

    int e = 0;
    for(e; e< E; e+=1){
        int u = graph -> next[e].src;
        int v = graph -> next[e].dest;
        int w = graph -> next[e].weight;

        if(dist[u] != INF && dist[v] > dist[u] + w){
            dist[v] = dist[u] + w;
        }
    }

    // After this print the solution. //
    print(dist, V);
}

void print(int dist[], int size){
    int i = 0;
    for(i; i<size; i+=1){
        printf("%d \t\t %d\n", i, dist[i]);
    }
}

void main(){
    // Create a graph first of all. //
    Graph *graph = create(5, 6);

    // The graph has 5 vertices and 6 edges. //

    // add egde 0-1. //
    graph -> next[0].src = 0;
    graph -> next[0].dest = 1;
    graph -> next[0].weight = 1;

    // add edge 1-2. //
    graph -> next[1].src = 1;
    graph -> next[1].dest = 2;
    graph -> next[1].weight = 10;

    // add edge 2-3. //
    graph -> next[2].src = 2;
    graph -> next[2].dest = 3;
    graph -> next[2].weight = 11;

    // add edge 3-4. //
    graph -> next[3].src = 3;
    graph -> next[3].dest = 4;
    graph -> next[3].weight = 5;

    // add edge 4-0. //
    graph -> next[4].src = 4;
    graph -> next[4].dest = 0;
    graph -> next[4].weight = 2;

    // add edge 4-1. //
    graph -> next[5].src = 4;
    graph -> next[5].dest = 1;
    graph -> next[5].weight = 6;

    bellmanFord(graph, 0);
}
