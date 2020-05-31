#include <stdio.h>
#include <stdlib.h>

int A[10][10],n,v[10],topo[10],k=0;
void dfs(int s){
    int i;
    v[s]=1;
    for(i=0;i<n;i++){
        if(A[s][i]==1 && v[i]==0){
           dfs(i);


        }
    }
    topo[k++]=s;


}
int main()
{  int i,j;
     for(int i=0;i<n;i++){
        v[i]=0;
        topo[i]=0;
     }

    printf("Enter the number of vertices\n");
    scanf("%d",&n);
    printf("enter the adjacency matrix\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&A[i][j]);
        }
    }
    printf("Topological order\n");
     for(i=0;i<n;i++){
        if(v[i]==0){
            dfs(i);
        }
    }
     for(i=n-1;i>=0;i--)
    //for(int i=0;i<n;i++)
        printf("%d\t",topo[i]);
    return 0;
}
