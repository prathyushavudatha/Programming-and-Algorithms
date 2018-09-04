#include <stdio.h>
#include <string.h>

int main()
{
    int a[100],b[100];
    int ans[200]={0};
    int i,j,tmp;
    printf("enter the first number \n");

    char s1[101],s2[101];
    scanf(" %s",s1);
    printf("enter the sec number \n");
    scanf(" %s",s2);
    int l1 = strlen(s1);
    int l2 = strlen(s2);
    i = l1-1,j=0;
    while(i>=0)

    {
        a[j] = s1[i]-'0';
    i--;j++;
    }

    i = l2-1;j=0;
    while(i>=0)
    {
        b[j] = s2[i]-'0';
        i--;j++;
    }
    i = 0;

    do {
        for(j = 0;j < l1;j++)
        {
            ans[i+j] += b[i]*a[j];
        }
        i++;
    }while(i < l2);

        i = 0;

    do{
        tmp = ans[i]/10;
        ans[i] = ans[i]%10;
        ans[i+1] = ans[i+1] + tmp;
        i++;
    } while(i < l1+l2);
    i = l1+l2;

    do{
        if(ans[i] > 0)
            break;i--;
    }while ( i>= 0);

    printf(" The Product is  : ");
    for(;i >= 0;i--)
    {
        printf("%d",ans[i]);
    }
    return 0;
}
