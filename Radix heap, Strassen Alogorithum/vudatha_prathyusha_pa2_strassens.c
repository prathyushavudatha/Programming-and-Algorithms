#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
#include <time.h>


int stand_multi(int matrix1[100][100],int matrix2[100][100],int size)
{
    int i,j,k;

    int res[100][100];
      for(i=0; i<size; ++i)
        for(j=0; j<size; ++j)

            for(k=0; k<size; ++k )
            {
                res[i][j]+= matrix1[i][k] * matrix2[k][j];

            }

            for (i=0 ; i<size ; i++) {
        for (j=0 ; j<size ; j++)
            printf("%3d ", res[i][j]);
        printf("\n");
    }
    printf("\n");



    return 0;
}


int assign(int matix_to[100][100],int matrix_from[100][100],int size)
{

    int i,j;
    for (i=0;i<=size;i++)
    {
        for (j=0;j<=size;j++){
        matix_to[i][j] = matrix_from[i][j];
        }}
        return matix_to;
}

int plus(int matrix1[100][100], int matrix2[100][100],int size)
{
    int result[100][100];

    int m1_i, m1_j;
    int m2_i, m2_j;
    int i, j;
    int n = size;

    int result_rs,result_re,result_cs,result_ce;

    result_rs = result_cs = 0;
    result_re = result_ce = n;

     int m1_rs,m1_re,m1_cs,m1_ce,m2_cs,m2_ce,m2_rs,m2_re;
    m1_rs=m2_cs = m1_cs = m2_rs = 0;
    m2_ce=m2_re = m1_re =m1_ce = size;

    m1_i=m1_rs; m2_i=m2_rs; i=0 ;
    m1_j=m1_cs; m2_j=m2_cs; j=0 ;

    while ( m1_i<=m1_re ){
       while ( m1_j<=m1_ce ){
            result[i][j] = matrix1[m1_i][m1_j] + matrix2[m2_i][m2_j];
       }
    }
            m1_j++; m2_j++; j++;
            m1_i++;m2_i++; i++;

    return result;
}

int minus(int matrix1[100][100], int matrix2[100][100],int size)
{
    int result[100][100];

    int m1_i, m1_j;
    int m2_i, m2_j;
    int i, j;
    int n = size;

    int result_rs,result_re,result_cs,result_ce;

    result_rs = result_cs = 0;
    result_re = result_ce = n;

     int m1_rs,m1_re,m1_cs,m1_ce,m2_cs,m2_ce,m2_rs,m2_re;
    m1_rs=m2_cs = m1_cs = m2_rs = 0;
    m2_ce=m2_re = m1_re =m1_ce = size;


    m1_i=m1_rs; m2_i=m2_rs; i=0 ;
    m1_j=m1_cs; m2_j=m2_cs; j=0 ;

    while ( m1_i<=m1_re ){
       while ( m1_j<=m1_ce ){
            result[i][j] = matrix1[m1_i][m1_j] - matrix2[m2_i][m2_j];
       }
    }
            m1_j++; m2_j++; j++;
            m1_i++;m2_i++; i++;

    return result;
}


int display(int  matrix[100][100],int size)
{
    int i, j;
    int matrix_rs;

    for (i=0 ; i<size ; i++) {
        for (j=0 ; j<size ; j++)
            printf("%3d ", matrix[i][j]);
        printf("\n");
    }
    printf("\n");

    return matrix;
}


int strassen_multi (int matrix1[100][100], int matrix2[100][100], int size)
{

     int res[100][100];
    int A[100][100],B[100][100], C[100][100], D[100][100], E[100][100], F[100][100], G[100][100], H[100][100];
    int P1[100][100], P2[100][100], P3[100][100], P4[100][100], P5[100][100], P6[100][100], P7[100][100];
    int   Q1[100][100], Q2[100][100], Q3[100][100], Q4[100][100];
    int result[100][100];


    int m1_i, m1_j;
    int i, j;
    int n = size;

    int result_rs =0; int result_cs = 0;
    int result_ce =n-1 ;int result_re = n-1;

    int m1_rs,m1_re,m1_cs,m1_ce,m2_cs,m2_ce,m2_rs,m2_re;
    m1_rs=m2_cs = m1_cs = m2_rs = 0;
    m2_ce=m2_re = m1_re =m1_ce = size;

     int k;

      for(i=0; i<size; ++i)
        for(j=0; j<size; ++j)

            for(k=0; k<size; ++k )
            {
                res[i][j]+= matrix1[i][k] * matrix2[k][j];

            }

            for (i=0 ; i<size ; i++) {
        for (j=0 ; j<size ; j++)
            printf("%3d ", res[i][j]);
        printf("\n");
    }
    printf("\n");


    int A_rs,A_re,A_cs,A_ce;

    A_rs = m1_rs;
    A_re = m1_re/2;
    A_cs = m1_cs;
    A_ce = m1_ce/2;

     for ( i=A_rs;i<A_re;i++)
    {
        for (j=A_cs;j<A_ce;j++){
            A[i][j] = matrix1[i][j];
        }
    }


    int B_rs,B_re,B_cs,B_ce;

    B_rs = m1_rs;
    B_re = m1_re/2-1;
    B_cs = m1_ce/2 ;
    B_ce = m1_ce;

    for ( i=B_rs;i<=B_re;i++)
    {
        for (j=B_cs;j<=B_ce;j++){
            B[i][j] = matrix1[i][j];
        }
    }


     int C_rs,C_re,C_cs,C_ce;

    C_rs = m1_re/2 ;
    C_re = m1_re;
    C_cs = m1_cs;
    C_ce = m1_ce/2 -1;

    for ( i=C_rs;i<=C_re;i++)
    {
        for (j=C_cs;j<=C_ce;j++){
            C[i][j] = matrix1[i][j];
        }
    }

     int D_rs,D_re,D_cs,D_ce;

   D_rs = m1_re/2;
   D_re = m1_re;
   D_cs = m1_ce/2;
   D_ce = m1_ce;

   for ( i=D_rs;i<=D_re;i++)
    {
        for (j=D_cs;j<=D_ce;j++){
            D[i][j] = matrix1[i][j];
        }
    }

    int E_rs,E_re,E_cs,E_ce;


    E_rs = m2_rs;
    E_re = m2_re/2;
    E_cs = m2_cs;
    E_ce = m2_ce/2;

    for ( i=E_rs;i<E_re;i++)
    {
        for (j=E_cs;j<E_ce;j++){
            E[i][j] = matrix2[i][j];
        }
    }

     int F_rs,F_re,F_cs,F_ce;
    F_rs = m2_rs;
    F_re = m2_re/2-1;
    F_cs = m2_ce/2;
    F_ce = m2_ce;
    for ( i=F_rs;i<=F_re;i++)
    {
        for (j=F_cs;j<=F_ce;j++){
            F[i][j] = matrix2[i][j];
        }
    }

     int G_rs,G_re,G_cs,G_ce;

    G_rs = m2_re/2 ;
    G_re = m2_re;
    G_cs = m2_cs;
    G_ce = m2_ce/2-1;

    for ( i=G_rs;i<=G_re;i++)
    {
        for (j=G_cs;j<=G_ce;j++){
            G[i][j] = matrix2[i][j];
        }
    }

     int H_rs,H_re,H_cs,H_ce;

    H_rs = m2_re/2;
    H_re = m2_re;
    H_cs = m2_ce/2;
    H_ce = m2_ce;

    for ( i=H_rs;i<=H_re;i++)
    {
        for (j=H_cs;j<=H_ce;j++){
            H[i][j] = matrix2[i][j];
        }
    }



    assign(P1,stand_multi(A, minus(F, H,size),size),size);
    //display (P1,size);
    assign(P2,stand_multi(plus(A, B,size), H,size),size);
    assign(P3,stand_multi(plus(C, D,size), E,size),size);
    assign(P4,stand_multi(D, minus(G, E,size),size),size);
    assign(P5,stand_multi(plus(A, D,size), plus(E, H,size),size),size);
    assign(P6,stand_multi(minus(B, D,size), plus(G, H,size),size),size);
    assign(P7,stand_multi(minus(A, C,size), plus(E, F,size),size),size);

    assign(Q1, plus(minus(plus(P5, P4,size),P2,size), P6,size),size);
    assign(Q2,plus(P1, P2,size),size);
    assign(Q3,plus(P3, P4,size),size);
    assign(Q4,minus(minus(plus(P1, P5,size), P3,size), P7,size),size);


    int Q2_rs,Q2_re,Q2_cs,Q2_ce;
    int Q1_rs,Q1_re,Q1_cs,Q1_ce;
    int Q3_rs,Q3_re,Q3_cs,Q3_ce;
    int Q4_rs,Q4_re,Q4_cs,Q4_ce;


    Q1_cs = Q1_rs = Q2_cs = Q2_rs = Q3_cs = Q3_rs = Q4_cs = Q4_rs = 0;
    Q1_ce = Q1_re = Q2_ce = Q2_re = Q3_ce = Q3_re = Q4_ce = Q4_re = size;



    for (m1_i=Q1_rs, i=0 ; m1_i<=Q1_re ; m1_i++, i++){
        for (m1_j=Q1_cs, j=0 ; m1_j<=Q1_ce ; m1_j++, j++){
            result [i][j] = Q1 [m1_i][m1_j];
        }}


    m1_i=Q2_rs;
     i=0 ;
     m1_j=Q2_cs;
      j=n/2 ;
    while (m1_i<=Q2_re ){
        while( m1_j<=Q2_ce ){
            result [i][j] = Q2 [m1_i][m1_j];
        }
    }
    m1_i++; i++;
    m1_j++; j++;



    m1_i=Q3_rs;
     i=n/2 ;
     m1_j=Q3_cs;
     j=0 ;
    while( m1_i<=Q3_re  ){
        while ( m1_j<=Q3_ce ){
            result [i][j] = Q3 [m1_i][m1_j];
        }
    }
    m1_i++;
     i++;
     m1_j++;
     j++;

    m1_i = Q4_rs;
    i=n/2;
    m1_j=Q4_cs;
    j=n/2 ;
    while( m1_i<=Q4_re  ){
       while (m1_j<=Q4_ce  ){
            result [i][j] = Q4 [m1_i][m1_j];
        }}
        m1_i++;
         i++;
         m1_j++;
         j++;


    return 0;
}





int main( )
{

    //int m1[100][100],m2[100][100];
    int N;
    int val1,val2;
    int k,i,j;
    int M1[100][100], M2[100][100];

    printf("value of N \n");
    scanf("%d",&N);
    int M1rs,M1cs,M2rs,M2cs;
    int M1re,M1ce,M2ce,M2re;


     M1rs = M1cs = M2rs = M2cs =0;
    M1re = M1ce = M2ce = M2re = N-1;

    printf("Matrix is \n");
   srand(time(NULL));
    for( i=0;i<N;i++){
        for(j=0;j<N;j++){
            for (k=1; k<=N*N; k++){
                val1= rand()%99;
                val2= rand()%99;
          M1[i][j]= val1;
           M2[i][j]= val2;
            }
        }
    }

    printf("matrix 1 is \n");
    for( i=0;i<N;i++){
        for( j=0;j<N;j++){
            printf( " %d \t", M1[i][j] );
        }
        printf("\n");
    }
     printf("\n");

        printf("matrix 2 is \n");
          for( i=0;i<N;i++){
        for( j=0;j<N;j++){
              printf("%d \t", M2[i][j] );
        }
        printf("\n");
          }


     printf("standard  multiplication is \n \n");
     stand_multi(M1,M2,N);




   printf("Strassen’s multiplication  is \n \n");
   strassen_multi(M1,M2,N);


   return 0;

}

