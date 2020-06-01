#include <stdbool.h>
#include <limits.h>
#include <stdio.h>
int V;
int minDistance(int dist[], bool sptSet[])
{
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}
int printSolution(int dist[])
{
	printf("Vertex \t\t Distance from Source\n");
	for (int i = 0; i < V; i++)
		printf("%d \t\t %d\n", i, dist[i]);
}
void dijkstra(int graph[V][V], int src)
{
	int dist[V];
	bool sptSet[V]; //vertices in shortest path
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, sptSet[i] = false;
	dist[src] = 0;
	for (int count = 0; count < V - 1; count++) { //until all vertices are not included (V-1 because because source is already included)
		int u = minDistance(dist, sptSet);
		sptSet[u] = true;
		for (int v = 0; v < V; v++) //not visited and adjacent and cost+dist<dist
			if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
	}
	printSolution(dist);
}
int main()
{
	int i,j;
    printf("\nEnter number of vertices\n");
    scanf("%d",&V);
    int graph[V][V];
    printf("\nInsert Adjacency Matrix\n");
    for(i=0;i<V;i++)
    {
        for(j=0;j<V;j++)
        {
            scanf("%d",&graph[i][j]);
        }
    }
	dijkstra(graph, 0);
	return 0;
}
/*
1) Create a set sptSet (shortest path tree set) that keeps track of vertices included in shortest path tree, 
i.e., whose minimum distance from source is calculated and finalized. Initially, this set is empty.
2) Assign a distance value to all vertices in the input graph. Initialize all distance values as INFINITE. 
Assign distance value as 0 for the source vertex so that it is picked first.
3) While sptSet doesn’t include all vertices
….a) Pick a vertex u which is not there in sptSet and has minimum distance value.
….b) Include u to sptSet.
….c) Update distance value of all adjacent vertices of u. To update the distance values, iterate through all adjacent vertices. 
For every adjacent vertex v, if sum of distance value of u (from source) and weight of edge u-v, is less than the distance value of v, then update the distance value of v.
*/
