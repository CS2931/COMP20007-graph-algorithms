/* * * * * * *
 * Module containing various graph algorithms.
 *
 * created for COMP20007 Design of Algorithms 2020
 * by Tobias Edwards <tobias.edwards@unimelb.edu.au>
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "graph.h"
#include "graphalgs.h"
#include "list.h"

// ----- Prototypes for non-exposed functions -----

// Recursive explore function which explores from node u in the graph.
// order and visited are arrays of length n_vertices, n_visited is a pointer
// to the number of nodes which have already been visited.
//
// order[i] == k means that vertex k was visited ith in the order, while
// visited[i] == true means that node i has been visited
void dfs_explore(Graph *graph, int u, int *order, bool *visited, int *n_visited);


// Iterative explore function which explores from node u in the graph.
// order and visited are arrays of length n_vertices, n_visited is a pointer
// to the number of nodes which have already been visited.
//
// order[i] == k means that vertex k was visited ith in the order, while
// visited[i] == true means that node i has been visited
void bfs_explore(Graph *graph, int u, int *order, bool *visited, int *n_visited);

// ----- Function implementations -----

// Runs a depth first search on the given graph, returning a dynamically
// allocated array of integers representing the order in which the DFS
// visits the nodes in the graph.
//
// The resultant array will be of size n_vertices and must be freed after use.
int *dfs(Graph *graph) {
  int n = graph_num_vertices(graph);
  int *order = malloc(sizeof(int) * n);
  assert(order);
  // Use calloc to allocate and set all memory to 0
  bool *visited = calloc(n, sizeof(bool));
  assert(visited);

  int n_visited = 0;

  for (int u = 0; u < n; u++) {
    if (!visited[u]) {
      dfs_explore(graph, u, order, visited, &n_visited);
    }
  }

  free(visited);
  return order;
}

// Recursive explore function which explores from node u in the graph.
// order and visited are arrays of length n_vertices, n_visited is a pointer
// to the number of nodes which have already been visited.
//
// order[i] == k means that vertex k was visited ith in the order, while
// visited[i] == true means that node i has been visited
void dfs_explore(Graph *graph, int u, int *order, bool *visited, int *n_visited) {
  visited[u] = true;
  order[*n_visited] = u;
  (*n_visited)++;

  // Create an array to hold the neighbors of u
  int n_neighbours = graph_out_degree(graph, u);
  int *neighbours = malloc(sizeof(int) * n_neighbours);
  // Retrieve these neighbours from the graph
  graph_get_neighbours(graph, u, neighbours, NULL, n_neighbours);

  int v;
  for (int i = 0; i < n_neighbours; i++) {
    v = neighbours[i];
    if (!visited[v]) {
      dfs_explore(graph, v, order, visited, n_visited);
    }
  }

  free(neighbours);
}

int *bfs(Graph *graph) {
  int n = graph_num_vertices(graph);

  int *order = malloc(sizeof(int) * n);
  assert(order);

  // Use calloc to allocate and set all memory to 0
  bool *visited = calloc(n, sizeof(bool));
  assert(visited);
  int n_visited = 0;

  for (int u = 0; u < n; u++) {
    if (!visited[u]) {
      bfs_explore(graph, u, order, visited, &n_visited);
    }
  }

  free(visited);
  return order;
}

// Iterative explore function which explores from node u in the graph.
// order and visited are arrays of length n_vertices, n_visited is a pointer
// to the number of nodes which have already been visited.
//
// order[i] == k means that vertex k was visited ith in the order, while
// visited[i] == true means that node i has been visited
void bfs_explore(Graph *graph, int u, int *order, bool *visited, int *n_visited) {
  // use a list here
  // add to end, retrieve from start by convention will act as queue
  List *list = new_list();
  list_add_end(list, u);

  while (list_is_empty(list) == false) {
    int current = list_remove_start(list);

    // go through the neighbour retrieval pickle
    int n_neighbours = graph_out_degree(graph, current);
    int *neighbours = malloc(sizeof(int) * n_neighbours);
    graph_get_neighbours(graph, current, neighbours, NULL, n_neighbours);

    // process layer of neighbours
    for (int i = 0; i < n_neighbours; i++) {
      int k = neighbours[i];
      if (visited[k] == 0) {
        visited[k] = 1;
        order[*n_visited] = k;
        (*n_visited)++;
        list_add_end(list, k);
      }
    }

    free(neighbours);
  }

  free_list(list);
}