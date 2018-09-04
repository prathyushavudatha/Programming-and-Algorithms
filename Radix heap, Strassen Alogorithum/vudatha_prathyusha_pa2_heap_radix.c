#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main()
{

    int arr_radix[1000],num,arr_heap[1000];
    int i,j;
    printf("Input number of elements in array\n");
    scanf("%d",&num);
    if (0<=num && num >= 10000)
        {
        printf(" sorting method is not supported, please give a value between 0 to 10000");
        }
        else
        {
    printf("randomly generated array is : \n");

    //.....generate random numbers........................
    printf("random numbers for radix is \n ");
    srand(time (0));
    for(i=0;i<num;i++)
    {
    arr_radix[i]=rand()%999;

      printf("%d\n", arr_radix[i]);
    }

    printf("random numbers for heap is \n ");
    srand(time (0));
    for(i=0;i<num;i++)
    {
    arr_heap[i]=rand()%9;

      printf("%d\n", arr_heap[i]);
    }


if (num<=20){
    printf("...unsorted list \n");
    i=0;
    while(i<num )
        {
            j=arr_heap[i];
        while(j>=1)
        {
            printf("* ");
            j--;
        }
        printf("\n");
         i++;
    }
    }



//.........input from user..............
int input;

    printf ("enter 1 for radix sort \n");
    printf("enter 2 for heap  sort \n");

    printf( "Selection: " );
    scanf( "%d", &input );
    switch (input)
    {

    case 1:printf(".....executing radix sort....  \n");
        RadixSort(arr_radix,num);
        printf("The sorted elements are ::  ");
        for(i = 0; i < num; i++)
        printf("%d  ",arr_radix[i]);
        printf("\n");
    break;
    case 2:printf(".....executing heap sort.... \n");
        heapsort(arr_heap,num);
        printf("\nThe Sorted Elements Are:\n");
        for (i=0;i<num;i++)
        printf("\t%d",arr_heap[i]);
        printf("\n");
    break;

       default:
            printf( "Invalid input \n" );
            break;
    }

    if(num<=20 && input == 2){
    //sorted list
    printf("....sorted list\n");

    i=0;
    while( i<num)
        {
            j=arr_heap[i];
        while( j>=1)
            {
            printf("* ");
            j--;
            }
            printf("\n");
            i++;
    }
    return 0;
    }
        }
}




//......radix sort..............

 void RadixSort(int a[], int n)
{

    int bucket[10][10], bucket_count[10];
    int i, j, k, remainder, NOP=0, divisor=1, large, pass;

    while(large > 0)
    {
        NOP++;
        large/=10;
    }
    pass = 0;

   while( pass < NOP )

    {
        i = 0;
        while( i < 10 )
        {
            bucket_count[i] = 0;
                i++;
        }
        i = 0;
        while( i < n )
        {
            remainder = (a[i] / divisor) % 10;
            bucket[remainder][bucket_count[remainder]] = a[i];
            bucket_count[remainder] += 1;
            i++;
        }

        i = 0;
        for(k = 0; k < 10; k++)
        {
            j = 0;
            while( j < bucket_count[k] )
            {
                a[i] = bucket[k][j];
                i++;
                j++;
            }
        }
        divisor *= 10;

        for(i = 0; i < n; i++)
            printf("%d  ",a[i]);
        printf("\n");
        pass++;
    }
}

//............heap sort.......

void heapsort(int a[],int n) {
	int i,t;
	heapify(a,n);
	i=n-1;
	while(i>0) {
		t = a[0];
		a[0] = a[i];
		a[i] = t;
		adjust(a,i);
		i--;
	}
}
void heapify(int a[],int n) {
	int k,i,j,item;

	//for (k=1;k<n;k++)
        k=1;
        do{
		item = a[k];
		i = k;
		j = (i-1)/2;


		do{
			a[i] = a[j];
			i = j;
			j = (i-1)/2;
		}while((i>0)&&(item>a[j])) ;
		a[i] = item;
		k++;
	}while(k<n);
}
void adjust(int a[],int n) {
	int i,j,item;
	j = 0;
	item = a[j];
	//i = 2*j+1;
	//while(i<=n-1)
       for(i = 2*j+1;i<=n-1;i = 2*j+1) {
		if(i+1 <= n-1)

		   if(a[i] <a[i+1])

		    i++;
		if(item<a[i]) {
			a[j] = a[i];
			j = i;
			//i = 2*j+1;
		} else
		   break;
	}
	a[j] = item;
}



