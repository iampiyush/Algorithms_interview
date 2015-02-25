#include<iostream>
#include <list>
#include <limits.h>

using namespace std;

class AdjListNode
{
int v;
int weight;
public:
AdjListNode(int _v, int _w) { v = _v; weight = _w;}
int getV() { return v; }
int getWeight() { return weight; }
};

class Graph
{
int V; // No. of vertices'
// Pointer to an array containing adjacency lists
list<AdjListNode> *adj;


public:
Graph(int V); // Constructor

// function to add an edge to graph
void addEdge(int u, int v, int weight);
void prims_mst();
void print_mst(int parent[]);
int min_dist(int dist[],bool sptSet[]);

};

Graph::Graph(int V)
{
this->V = V;
adj = new list<AdjListNode>[V];
}

void Graph::addEdge(int u, int v, int weight)
{
AdjListNode node(v, weight);
adj[u].push_back(node); // Add v to u's list
}

int Graph::min_dist(int dist[],bool sptSet[])
{
int min = INT_MAX, min_index;

for (int v = 0; v < V; v++)
if (sptSet[v] == false && dist[v] <= min)
min = dist[v], min_index = v;

return min_index;
}

void Graph::print_mst(int parent[])
{
cout<<"edges in the MST are"<<endl;
for(int i=1;i<V;i++)
{
cout<<parent[i]<<"---"<<i;
cout<<endl;
}
}

void Graph::prims_mst()
{
int parent[V]; // Array to store constructed MST
int key[V]; // Key values used to pick minimum weight edge in cut
bool mstSet[V]; // To represent set of vertices not yet included in MST

// Initialize all keys as INFINITE
for (int i = 0; i < V; i++)
key[i] = INT_MAX, mstSet[i] = false;

// Always include first 1st vertex in MST.
key[0] = 0; // Make key 0 so that this vertex is picked as first vertex
parent[0] = -1; // First node is always root of MST
for(int v=0;v<V;v++)
{
int u=min_dist(key,mstSet);
mstSet[u]=true;
list<AdjListNode>::iterator i;
for(i=adj[u].begin();i!=adj[u].end();i++)
{
if(mstSet[i->getV()]==false && i->getWeight() < key[i->getV()])
parent[i->getV()]=u,key[i->getV()]=i->getWeight();
}
}
print_mst(parent);
}

int main()
{

Graph g(9);
g.addEdge(0, 1, 4);
g.addEdge(1, 0, 4);
g.addEdge(0, 7, 8);
g.addEdge(7, 0, 8);
g.addEdge(1, 2, 8);
g.addEdge(2, 1, 8);
g.addEdge(1, 7, 11);
g.addEdge(7, 1, 11);
g.addEdge(2, 3, 7);
g.addEdge(3, 2, 7);
g.addEdge(2, 8, 2);
g.addEdge(8, 2, 2);
g.addEdge(2, 5, 4);
g.addEdge(5, 2, 4);
g.addEdge(3, 4, 9);
g.addEdge(4, 3, 9);
g.addEdge(3, 5, 14);
g.addEdge(5, 3, 14);
g.addEdge(4, 5, 10);
g.addEdge(5, 4, 10);
g.addEdge(5, 6, 2);
g.addEdge(6, 5, 2);
g.addEdge(6, 7, 1);
g.addEdge(7, 6, 1);
g.addEdge(6, 8, 6);
g.addEdge(8, 6, 6);
g.addEdge(7, 8, 7);
g.addEdge(8, 7, 7);


g.prims_mst();

return 0;
} 
