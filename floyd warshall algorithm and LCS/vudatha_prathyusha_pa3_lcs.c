#include<stdio.h>
#include<string.h>

int i,j,m,n,c[100][100];
char x[100],y[100],b[100][100];



void lcs(int k,int l)
{

                for(i=0,j=0;i<=m,j<=n;i++,j++)
                    {

                                c[i][j]=0; //initilazing all c matrix values to 0
                }


                i=1;
                do{
                                j=1;
                                while(j<=n)
                                {

                                                 if(c[i-1][j]<c[i][j-1])
                                                {
                                                              c[i][j]=c[i][j-1];
                                                                b[i][j]='d'; // d denotes downward direction
                                                }
                                                else if(x[i-1]==y[j-1])
                                                {
                                                                c[i][j]=c[i-1][j-1]+1;
                                                                b[i][j]='c';  // c denotes cross direction
                                                }
                                                else
                                                {
                                                                 c[i][j]=c[i-1][j];
                                                                b[i][j]='u'; // u denotes upword direction
                                                }
                                j++;
                                }
                                i++;
                }while(i<=m);


                 if(k==0 || l==0)
                 {
                     return;
                 }

                else if(b[k][l]=='u')
                {
                                lcs(k-1,l);
                }
                else if(b[k][l]=='c')
                {
                                lcs(k-1,l-1);
                                printf("%c",x[k-1]);
                }

                else
                {

                                lcs(k,l-1);
                }

}

int main()
{
                printf("Enter the first sequence:");
                scanf("%s",x);
                printf("Enter the second  sequence:");
                scanf("%s",y);
                m=strlen(x);
                n=strlen(y);
                printf("\n");
                printf("The Longest Common Subsequence is \n");
                lcs(m,n);
		printf("\n");
                return 0;
}
