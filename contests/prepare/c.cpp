#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
using namespace std;

struct Edge
{
    int src, dest;
};
 
// a structure to represent a graph
struct Graph
{
    // V-> Number of vertices, E-> Number of edges
    int V, E;
 
    // graph is represented as an array of edges
    struct Edge* edge;
};
 
struct subset
{
    int parent;
    int rank;
};
 
// Creates a graph with V vertices and E edges
struct Graph* createGraph(int V, int E)
{
    struct Graph* graph = (struct Graph*) malloc( sizeof(struct Graph) );
    graph->V = V;
    graph->E = E;
 
    graph->edge = (struct Edge*) malloc( graph->E * sizeof( struct Edge ) );
 
    return graph;
}
 
// A utility function to find set of an element i
// (uses path compression technique)
int find(struct subset subsets[], int i)
{
    // find root and make root as parent of i (path compression)
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
 
    return subsets[i].parent;
}
 
// A function that does union of two sets of x and y
// (uses union by rank)
void Union(struct subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
 
    // Attach smaller rank tree under root of high rank tree
    // (Union by Rank)
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
 
    // If ranks are same, then make one as root and increment
    // its rank by one
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int main() {
	long long n;
	cin >> n;

	struct Graph* graph = createGraph(n * 2, 0);

	int arr[n][2];
	long long ans = 0;
	for (long long i = 0; i < n; i++) {
		cin >> arr[i][0] >> arr[i][1];
	}

	for (long long i = 0; i < n; i++) {
		if () {
			ans + = 1;
		}
	}
	
	cout << ans;
	return 0;
}