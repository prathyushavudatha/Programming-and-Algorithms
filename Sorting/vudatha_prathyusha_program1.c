#include <stdio.h>
#include <stdlib.h>



int main()
{

        int arr[100],num;
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
    srand(time (0));
    for(i=0;i<num;i++)
    {
    arr[i]=rand()%5+1;

      printf("%d\n", arr[i]);
    }


    printf("...unsorted list \n");
    for(i=0; i<num; i++)
        {
        for(j=arr[i]; j>=1;j--)
        {
            printf("* ");
        }
        printf("\n");
    }

//.........input from user..............
int input;

    printf ("enter 1 for exchange sort \n");
    printf("enter 2 for insertion  sort \n");
    printf("enter 3 for merge sort \n");
    printf("enter 4 for randomized quick sort\n  ");
    printf( "Selection: " );
    scanf( "%d", &input );
    switch (input)
    {

    case 1:printf(".....executing exchange sort....  \n");
        exchange(arr,num);
    break;
    case 2:printf(".....executing insertion sort.... \n");
        insert(arr,num);
    break;
    case 3:printf(".....executing merge sort.... \n \n");
        mergesort(arr,0,num);
    break;
    case 4:printf(".....executing randamized quick  sort.... \n \n");
        quicksort(arr,0,num-1);
    break;
       default:
            printf( "Invalid input \n" );
            break;
    }


    //sorted list
    printf("....sorted list\n");
    for(i=0; i<num; i++)
        {
        for(j=arr[i]; j>=1;j--)
            {
            printf("* ");
            }
            printf("\n");
    }
    return 0;
    }
}






// .............insertion sort ................

  int insert(int a[], int n) //insert function
    {

        int temp,i,j; // deaclring variables
        for (i = 1; i < n; i++) {
            for( j = i ; j > 0 ; j--){
                if(a[j] < a[j-1]){
                    temp = a[j];
                    a[j] = a[j-1];  //logic to swap
                    a[j-1] = temp;
                }
            }
        }


    }


//...........merge sort................................

void mergesort(int a[],int i,int j)
{

    int mid;
    if(i<j)
    {
    mid=(i+j)/2;
    mergesort(a,i,mid);
    mergesort(a,mid+1,j);
    merge(a,i,mid,mid+1,j);
    }
    }


void merge(int a[],int i1,int j1,int i2,int j2)
    {
    int temp[50];
    int i,j,k;
    i=i1;
    j=i2;
    k=0;
    while(i<=j1&&j<=j2)
    {
    if(a[i]>a[j])
    temp[k++]=a[j++];
    else
    temp[k++]=a[i++];
    }
    while(i<=j1)
    temp[k++]=a[i++];
    while(j<=j2)
    temp[k++]=a[j++];
    for(i=i1,j=0;i<=j2;i++,j++)
    a[i]=temp[j];

    }

//..........randomized quick quick................



void swap (int a[], int left, int right)
{
 int temp;
 temp=a[right];
 a[right]=a[left];
 a[left]=temp;
}//end swap

void quicksort( int a[], int low, int high )
{
 int pivot;
 // Termination condition!
 if ( high > low )
 {
  pivot = partition( a, low, high );
  quicksort( a, low, pivot-1 );
  quicksort( a, pivot+1, high );
 }
} //end quicksort

int partition( int a[], int low, int high )
{
 int left, right;
 int pivot_item;
 int pivot = left = low;
 pivot_item = a[low];
 right = high;
 while ( left < right )
 {
  // Move left while item < pivot
  while( a[left] <= pivot_item )
   left++;
  // Move right while item > pivot
  while( a[right] > pivot_item )
   right--;
  if ( left < right )
   swap(a,left,right);
 }
 // right is final position for the pivot
 a[low] = a[right];
 a[right] = pivot_item;
 return right;
}//end partition



  // .....exchnage sort......................


int exchange (int arr[], int size)
    {
        int temp ,k,i,l;
        for ( i=0;i<=size;i++)
        {
            for ( k=1;k<=size;k++)
            {
                for ( l=0; l<size;l++)
                {
                    if ( arr[k] < arr[l])
                    {
                        temp = arr[k];
                        arr[k] = arr[l];
                        arr[l] = temp;
                    }
                }
            }

        }

    }
