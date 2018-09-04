#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#define MAX 50
 int n;
int mincost=0,parent[50];
int find3(int);
int union3(int,int);
void kush();
void print();


void main()
{
    int i ,j,val1,cost[MAX][MAX];

   srand(time (0));
    n = 5 + rand() %5;

   printf("Ramndomly generated number of vertices are is %d \n", n);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
                val1 =  4+ rand() % 5;
                if (i == j){
                cost[i][j] = 0;
                }
            else
            {
                cost[i][j] = cost[j][i] = val1;
            }

        }
    }
    printf(" randomly created adjesency undirected  matrix is \n");
    for( i=1;i<=n;i++){
        for( j=1;j<=n;j++){
            printf( " %d \t", cost[i][j] );
        }
        printf("\n");
    }

     for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
              if(cost[i][j]==0)
            cost[i][j]=999;
        }
        }

        kush(cost);
        print();
}



void kush(int cost[MAX][MAX])
{
int i,j,a,b,u,v,min;
 printf("\n The edges of Minimum Cost Spanning Tree are \n \n");
 int la;

 for(la=1;la<n;la++)
 {
    min=999;
   i=1;
  do{
        j=1;
   while(j<=n)
   {
    if(cost[i][j]<min)
    {
     min=cost[i][j];
     a=u=i;
     b=v=j;
    }
  j++;
   }
 i++;
  } while (i<=n);

  u=find3(u);
  v=find3(v);

  if(union3(u,v)==1)
  {
   printf("\n%d edge (%d,%d) =%d\n",la,a,b,min);
   mincost +=min;
  }
  cost[a][b]=cost[b][a]=999;
 }
}


void print()
{
    printf("\n Minimum cost is = %d\n",mincost);
}

int find3(int i)
{
 while(parent[i])
 {
   i=parent[i];
 }

 return i;
}

int union3(int i,int j)
{
 if(i==j)
 {
    return 0;
 }
 else
 {
    parent[j]=i;
  return 1;
 }

}
