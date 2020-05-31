#include <stdio.h>
#include <stdlib.h>
int M[10][10],visited[10],n;
void dfs(int v){
    int j;
    visited[v]=1;
    printf("%d\t",v);
    for(int j=0;j<n;j++){
        if(M[v][j]==1 && visited[j]==0)
            dfs(j);
    }
}
void bfs(int v){
    int i,queue[20],f=0,r=-1;
    visited[v]=1;
    printf("%d\t",v);
    queue[++r]=v;
    while(f<=r){
        v=queue[f++];
        for(int i=0;i<n;i++)
        {
            if(M[v][i]==1 && visited[i]==0)
            {
                visited[i]=1;
                queue[++r]=i;
                printf("%d\t",i);
            }
        }
    }

}
int main()
{
    int i,j,v,count=1,flag=0;
    printf("Enter the number of vertices\n");
    scanf("%d",&n);
    printf("enter the adjacency matrix\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&M[i][j]);
        }
    }
    printf("enter the starting node\n");
    scanf("%d",&v);
    printf("\nDFS\n");
    dfs(v);
    for(i=0;i<n;i++){
        if(visited[i]==0){
            dfs(i);
            count++;
        }
    }
    if(count==1) printf("Connected graph\n");
    else printf("Disconnected graph with %d components\n",count);
    count=1;
    for(i=0;i<n;i++)
        visited[i]=0;
    printf("\nBFS\n");
    bfs(v);
    for(i=0;i<n;i++){
        if(visited[i]==0){
            dfs(i);
            count++;
        }
    }
    if(count==1) printf("Connected graph\n");
    else printf("Disconnected graph with %d components\n",count);
    count=1;

    return 0;
}
