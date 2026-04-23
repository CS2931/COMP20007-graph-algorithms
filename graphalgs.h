/* * * * * * *
 * Module containing various graph algorithms.
 *
 * created for COMP20007 Design of Algorithms 2020
 * by Tobias Edwards <tobias.edwards@unimelb.edu.au>
 */

#ifndef GRAPHALGS_H
#define GRAPHALGS_H

#include "graph.h"
#include "list.h"

// Runs a depth first search on the given graph, returning a dynamically
// allocated array of integers representing the order in which the DFS
// visits the nodes in the graph.
//
// The resultant array will be of size n_vertices and must be freed after use.
int *dfs(Graph *graph);


// Runs a breadth first search on the given graph, returning a dynamically
// allocated array of integers representing the order in which the DFS
// visits the nodes in the graph.
//
// The resultant array will be of size n_vertices and must be freed after use.
int *bfs(Graph *graph);

// Runs dijkstras single source shortest path algorithm on the given graph
// sets results to the dist buffer provided
// dist is an array of size n_vertices, this function will produce an error if the memory isn't supplied
//
// dist[k] = w means that the shortest path from start to k is w, and this array must be freed after use
void dijkstras(Graph *graph, int start, int *dist, List **paths);

#endif
