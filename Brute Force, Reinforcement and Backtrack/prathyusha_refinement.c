#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include <math.h>
#include<stdio.h>
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

   int i,j,k;
    int val1;
    int wt[10],val[10],A[10];
    int n;
    int Capacity;

int main()
{

   // srand(time (0));
    n = 4 + rand() %4;
     printf("\n");
    printf("implementing the refinement algorithm of dynamic programming approach for the 0/1 knapsack problem: \n");
    printf("\n");
    printf("randomly created inteeger n  between 4 to 8 is %d \n", n);
    printf("\n");
    for (i=1;i<=n;i++)
    {
        wt[i] =  rand() %20 +10;
        val[i] =  rand() %15 + 5;

    }

      for (i=1;i<=n;i++)
        {
            printf("randomly created weight[%d]  is %d \n",i,wt[i]);
        }
        printf("\n");

         for (i=1;i<=n;i++)
        {
         printf("randomly created profit[%d]  is %d \n",i,val[i]);
        }
         printf("\n");

        int totalwei =0 ;
        int totalpro =0;
            for (i=1;i<=n;i++)
            {
                totalwei = totalwei + wt[i];
                totalpro = totalpro + val[i];
            }

        printf("total weight is %d \n", totalwei);
        printf("total profit is %d \n", totalpro);
         printf("\n");



            Capacity = floor(0.6 * totalwei );
             printf("Capacity is  %d \n", Capacity);
             printf("\n");

        printf("final solution is  %d\n", knapSack(Capacity, wt, val, n));
         printf("\n");
        return 0;
}

int knapSack(int W, int wt[], int val[], int n)
{
   int i, w;
   int K[n+1][W+1];
    i = 0;
   while( i <= n)
   {
       w = 0;

       do{
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (wt[i-1] <= w)

                 K[i][w] = MAX(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
                 w++;
       }while( w <= W);
        i++;

   }

   return K[n][W];
}






