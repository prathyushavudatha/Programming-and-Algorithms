#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()

{
    int N ;
    int i,j,k,val1,val2, m1[50][50];
   srand(time (0));

    N = 5 + rand() %6;
    printf("random number is %d \n", N);


    srand(time(NULL));

       for( i=1;i<N;i++){
        for(j=1;j<N;j++){
            for (k=1; k<=N*N; k++){

                val1 =  4+ rand() % 5;

            if (i == j)
            {
                m1[i][j] = 0;
            }
            else
            {
                m1[i][j] = m1[j][i] = val1;
            }

            }
        }
    }

    int dist[50][50];
    printf(" randomly created adjesency matric is  is \n");
    for( i=1;i<N;i++){
        for( j=1;j<N;j++){
            printf( " %d \t", m1[i][j] );
            dist[i][j] = m1[i][j];
        }
        printf("\n");
    }
     printf("\n");

	for (k = 1; k < N; k++)
	{
		for (i = 1; i < N; i++)
		{
		    j = 1;

			do{
				if((dist[i][k] + dist[k][j] )< (dist[i][j]))
					dist[i][j] = dist[i][k] + dist[k][j];
					 j++;
					 //printf("%d", dist[i][j] );

			}while ( j < N);
		}
	}


     printf("\n The shortest paths are: \n");
        for(i=1;i<N;i++)
        for(j=1;j<N;j++)

        if(i==j)
        {
             printf("\n <%d,%d> = %d",i,j,0);
        }
        else
        {
           printf("\n <%d,%d> = %d",i,j,dist[i][j]);
        }
		printf("\n");

    return 0;
}









