#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include <math.h>
#include<stdio.h>

int main()
{
    int i,j,k;
    int val1;
    int wt[10],val[10],A[10];
    int n;
   // srand(time (0));
    n = 4 + rand() %4;
    printf("\n");
    printf("Implement the brute force method to solve the 0/1 knapsack problem : \n");
    printf("\n");
    printf("randomly created inteeger n  between 4 to 8 is %d \n", n);
    printf("\n");
    for (i=1;i<=n;i++)
    {
        wt[i] =  rand() %20 +10;
        val[i] =  rand() %15 + 5;
        A[i] = 0;

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

        int Capacity;

            Capacity = floor(0.6 * totalwei );
             printf("Capacity is  %d \n", Capacity);
             printf("\n");

        printf("final solution is  %d\n", knapSack(Capacity, wt, val, n));
         printf("\n");
        return 0;
}

int knapSack(int W, int wt[], int val[], int n)
{

   if (n == 0 || W == 0)
       return 0;

   if (wt[n-1] > W)
       return knapSack(W, wt, val, n-1);

   else
   {
        if (( val[n-1] + knapSack(W-wt[n-1], wt, val, n-1)) > (knapSack(W, wt, val, n-1)) )
            {
                return val[n-1] + knapSack(W-wt[n-1], wt, val, n-1);
            }
            else{
                return knapSack(W, wt, val, n-1);
            }
   }


}

