#include <stdio.h>
#include <stdlib.h>



int main()
{   int indegree[10],stack[10],top=-1,n,result[10],A[10][10],i,j,k=0,flag=0,nd,vis[10];
     for(int i=0;i<n;i++){
        result[i]=0;
        indegree[i]=0;
        vis[i]=0;
     }
    printf("Enter the number of vertices\n");
    scanf("%d",&n);
    printf("enter the adjacency matrix\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&A[i][j]);
            if(A[i][j]==1)
                indegree[j]++;
        }
    }

    for(i=0;i<n;i++){
        if(indegree[i]==0){
           flag=1;
           break;
        }
    }
    if(flag==1){
        for(i=0;i<n;i++){
             if(indegree[i]==0)
                stack[++top]=i;
        }
        while(top!=-1){
            nd=stack[top--];
            result[k++]=nd;
            vis[nd]=1;
            for(i=0;i<n;i++){
                if(A[nd][i]==1)
                    indegree[i]--;
             }
             for(i=0;i<n;i++)
                if(indegree[i]==0 && vis[i]==0)
                    stack[++top]=i;
        }
        printf("Topological order\n");
        for(i=0;i<n;i++)
            printf("%d\t",result[i]);


    }
    else printf("cyclic graph\n");


    return 0;
}
