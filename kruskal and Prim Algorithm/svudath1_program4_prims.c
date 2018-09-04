#include<stdio.h>
#include<stdlib.h>
#include <time.h>



int G[50][50],spanning[50][50],n,total_cost;

void prims();
void print();


int main()
{
    int i,j;
    int val1;
   srand(time (0));
    n = 5 + rand() %5;
    printf("Number of vertices are is %d \n", n);

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
                val1 =  4+ rand() % 5;
                if (i == j){
                G[i][j] = 0;
                }
            else
            {
                G[i][j] = G[j][i] = val1;
            }
        }
    }

    printf(" randomly created adjesency undirected  matrix is \n");
    for( i=0;i<n;i++){
        for( j=0;j<n;j++){
            printf( " %d \t", G[i][j] );
        }
        printf("\n");
    }

    prims();

}


void prims()
{
    int cost[50][50];
    int u,v,min_distance,distance[50],from[50];
    int visited[50],no_of_edges,i,min_cost,j;

    //creating  cost[][] matrix,spanning[][]
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            if(G[i][j] !=0){
                cost[i][j]=G[i][j];
                spanning[i][j]=0;}
            else{
                cost[i][j]=999;}
        }

    //initialisint variables
    distance[0]=0;
    visited[0]=1;
    i=1;

    do{
        distance[i]=cost[0][i];
        from[i]=0;
        visited[i]=0;i++;
    } while(i<n);

    min_cost=0;
    for (no_of_edges=n-1;no_of_edges>0; no_of_edges--)
    {
        // to find the mim distant vertexes
        min_distance=999;
        for(i=1;i<n;i++)
        {
            if(visited[i]==0&&distance[i]<min_distance)
            {
                v=i;
                min_distance=distance[i];
            }
        }


        u=from[v];

        //spanning tree edge
        spanning[u][v]=distance[v];
        spanning[v][u]=distance[v];

        visited[v]=1;
            for(i=1;i<n;i++)
            if(visited[i]==0&&cost[i][v]<distance[i]) //checking is visited
            {
                distance[i]=cost[i][v];
                from[i]=v;
            }
        }
        min_cost=min_cost+cost[u][v];

    total_cost = min_cost;

    print();

}


void print() //print function for display
    {
    int i,j;
    printf("\nspanning tree matrix is :\n");
    i=0;
    do{
        printf("\n");
        for(j=0;j<n;j++)
            printf("%d\t",spanning[i][j]);
            i++;
    } while(i<n);

    for(i=0;i<n;i++)
        for (j=0;j<n;j++)
        if (spanning[i][j]!= 0){
        printf("\n Edge (%d %d) cost is %d",i,j,spanning[i][j]);
        }

    printf("\n");
    printf("\n");
   
    }
