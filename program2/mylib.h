#include <stdio.h>
#include <stdlib.h>


int myStrStr(char haystack[], char needle[], char buffer[])
{

        int i = 0, j = 0, k = 0, c = 0;
        while(haystack[i]!='\0')
    {
                if(haystack[i]!= needle[j])
            i++;
        else if(haystack[i] == needle[j])
        {
                buffer[k]=haystack[i];
                    i++;
                    j++;
                    c++;
        //          buffer[k] = haystack[i - 1];
                    k++;
        }
          else
          {
                    c=0;
                    break;
           }

        }
buffer[k]='\0';

     if(c!=0)
      {return 1;}
     else
      {return 0;}

}

unsigned int countOnes(int num)
{

int p,i=0,count=0;

int array[40];
  for (p = 31; p >= 0; p--)
  {
    array[p] = num >> p;

    if (array [p] & 1)
        array[p] = 1;
    else
        array[p] = 0;
  }
for(i=31;i>=0;i--)
{
if(array[i]==1)
count++;
//printf("%d",array[i]);
}
//printf("%d",count-1);
return (count);

}



void binaryArray(int n, int array[], int size)
    {
    array[size];
    int x;
    int y=0;
    while(size>=0)
        {
        x= n >> size-1;
        if(x & 1)
        array[y]=1;
        else
        array[y]=0;
        y++;
        size--;
        }
    }
void binaryPrinter(int array[], int size)
    {

    for(int ind = 0; ind <= size; ind++)
        {
        if((ind%4) == 0)
        printf(" ");
        printf("%d", array[ind]);
        }
    printf("\n");
    }

