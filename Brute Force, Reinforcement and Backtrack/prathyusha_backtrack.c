
#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include <math.h>
#include<stdio.h>
#define max 20

int w[max],i,j,p[max];
int n;
double m;
float unit[max];
int y[max],x[max],fp=-1,fw;
int k,cp,cw;

void knapsack(int k,float cp,float cw)
{

 if(cw+w[k] <= m)
   {
   y[k] = 1;
   if(k <= n)
      knapsack(k+1,cp+p[k],cw+w[k]);
   if(((cp+p[k]) > fp) && ( k == n))
      {
      fp = cp+p[k];
      fw = cw+w[k];
      j=0;
      while(j<=k)
      {
         x[j] = y[j];
         j++;
      }

      }
    }

{
 y[k] = 0;
 if( k <= n)
 knapsack(k+1,cp,cw);
 if((cp > fp) && (k == n))
   {
   fp = cp;
   fw = cw;
   j=0;
   while(j<=k)
   {
        x[j] = y[j];
        j++;
   }

   }
}
}

int main()
{

printf("\n\n\t  BACKTRACK KNAPSACK PROBLEM \n");
srand(time (0));
   n = 4 + rand() %4;

    printf("\n");
    printf("randomly created inteeger n  between 4 to 8 is %d \n", n);
    printf("\n");
    for (i=1;i<=n;i++)
    {
        w[i] =  rand() %20 +10;
        p[i] =  rand() %15 + 5;
    }
      for (i=1;i<=n;i++)
        {
            printf("randomly created weight[%d]  is %d \n",i,w[i]);
        }
        printf("\n");

         for (i=1;i<=n;i++)
        {
         printf("randomly created profit[%d]  is %d \n",i,p[i]);
        }
         printf("\n");

        int totalwei =0 ;
        int totalpro =0;
            for (i=1;i<=n;i++)
            {
                totalwei = totalwei + w[i];
            totalpro = totalpro + p[i];
            }

        printf("total weight is %d \n", totalwei);
        printf("total profit is %d \n", totalpro);
         printf("\n");
            m = floor(0.6 * totalwei );
             printf("Capacity is  %d \n", m);

knapsack(k,cp,cw);

for(i=0;i<n;i++)
    if (x[i] == 1)
    {
        printf("\nSelected Items are : ");
        printf("Item %d ",i+1);
    }
    float s= 0.0;
    i=0;
    while(i<n)
    {
        if(x[i]==1)
    {
   s = s + (float) p[i] * (float) x[i];
   }
        i++;
    }
printf("\n\n Maximum Profit: %f ",s);
  printf("\n");
return 0;
}
