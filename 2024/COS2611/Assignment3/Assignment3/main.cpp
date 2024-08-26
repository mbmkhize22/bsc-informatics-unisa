/*
 * Student Name: Muzikayise Bonginhlanhla Mkhize
 * Student Number: 59415983
 *
 * Question asked: "Generate C++ code that implements Prim’s algorithm using ADT with a time complexity of O(n^2)."
 *
 * Updates and Changes:
 * 1. Added functionality to read graph data from a file (fiberdata.txt).
 * 2. Modified the code to output the minimum spanning tree.
 */

#include <iostream>
#include <vector>
#include <limits.h>
#include <fstream>
using namespace std;

// Number of vertices in the graph
#define V 7

// Function to find the vertex with minimum key value, from the set of vertices not yet included in MST
int minKey(int key[], bool mstSet[])
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

// Function to print the constructed MST stored in parent[]
void printMST(int parent[], int graph[V][V])
{
    cout << "Minimum Spanning Tree using Prim’s Algorithm:\n";
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << " \n";
}

// Function to construct and print MST for a graph represented using adjacency matrix representation
void primMST(int graph[V][V])
{
    int parent[V]; // Array to store constructed MST
    int key[V];    // Key values used to pick minimum weight edge in cut
    bool mstSet[V]; // To represent set of vertices included in MST

    // Initialize all keys as INFINITE
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    // Always include first 1st vertex in MST.
    key[0] = 0;     // Make key 0 so that this vertex is picked as first vertex
    parent[0] = -1; // First node is always root of MST

    // The MST will have V vertices
    for (int count = 0; count < V - 1; count++)
    {
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int u = minKey(key, mstSet);

        // Add the picked vertex to the MST Set
        mstSet[u] = true;

        // Update key value and parent index of the adjacent vertices of the picked vertex.
        // Consider only those vertices which are not yet included in MST
        for (int v = 0; v < V; v++)

            // graph[u][v] is non zero only for adjacent vertices of m
            // mstSet[v] is false for vertices not yet included in MST
            // Update the key only if graph[u][v] is smaller than key[v]
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    // Print the constructed MST
    printMST(parent, graph);
}

// Main function
int main()
{
    int graph[V][V];

    // Reading graph from file
    ifstream file("c:\\data\\fiberdata.txt");
    if (!file) {
        cerr << "Unable to open file fiberdata.txt";
        exit(1); // terminate with error
    }

    int vertices, edges;
    file >> vertices >> edges;

    // Initialize graph with 0
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            graph[i][j] = 0;

    // Populate the graph from the file
    int u, v, weight;
    for (int i = 0; i < edges; i++) {
        file >> u >> v >> weight;
        graph[u][v] = weight;
        graph[v][u] = weight; // Since the graph is undirected
    }

    file.close();

    // Function call
    primMST(graph);

    return 0;
}
