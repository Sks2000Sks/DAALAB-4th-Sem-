#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#define V 5
int minKey(int weight[], bool mstSet[])
{
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (mstSet[v] == false && weight[v] < min)
			min = weight[v], min_index = v;
	return min_index;
}

int printMST(int parent[], int graph[V][V])
{
	printf("Edge \tWeight\n");
	for (int i = 1; i < V; i++)
		printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
}

void primMST(int graph[V][V])
{
	int parent[V];
	int weight[V]; 
	bool mstSet[V];

	for (int i = 0; i < V; i++)
		weight[i] = INT_MAX, mstSet[i] = false;
  
	weight[0] = 0;
	parent[0] = -1; 
	for (int count = 0; count < V - 1; count++) {
		int u = minKey(weight, mstSet);
		mstSet[u] = true;
		for (int v = 0; v < V; v++)
		  //adjacent and not visited and graph[u][v] is smaller than key[v]
			if (graph[u][v] && mstSet[v] == false && graph[u][v] < weight[v])
				parent[v] = u, weight[v] = graph[u][v];
	}
	printMST(parent, graph);
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
	primMST(graph); 
	return 0;
}
