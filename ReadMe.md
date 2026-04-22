This is my guide to the repo, the skeleton was provided by the COMP20007 team but I added the graph algorithms (not DFS)

Main.c
- reads in the graphs using its own methods, and builds the graph with methods provided by the graph module

Graph module
- methods for building and interacting with graphs
- The place to add calls to the algorithms I'll be building

List module
- implementation for a linked list where each node has an int data element
- has the notion of a list iterator to prevent exposing the underlying type

Priority queue module
- methods for building and interacting with a min PQ
- each node has an integer key and an integer priority
- implemented using an unsorted array (it will get reimplemented later)

Graph algs module
- The file that I'll be initially working on a lot
- DFS already implemented but I should be adding to this
