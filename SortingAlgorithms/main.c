
/** This program implements six sorting algorithms
    1 . selectionSort
    2 . insertionSort
    3 . bubbleSort
    4 . quickSort
    5 . mergeSort
    6 . heapSort
    

**/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>

#define RANGE 255

void swap(int *number_1, int *number_2)
{
    int temp = *number_1;
    *number_1 = *number_2;
    *number_2 = temp;
}

void bubbleSort(int array[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)
       for (j = 0; j < n-i-1; j++)
           if (array[j] > array[j+1])
              swap(&array[j], &array[j+1]);
}
void insertionSort(int array[], int n)
{
   int i, key, j;
   for (i = 1; i < n; i++)
   {
       key = array[i];
       j = i-1;
       while (j >= 0 && array[j] > key)
       {
           array[j+1] = array[j];
           j = j-1;
       }
       array[j+1] = key;
   }
}
void selectionSort(int array[], int n)
{
    int i, j, min;

    for (i = 0; i < n-1; i++)
    {
        min = i;
        for (j = i+1; j < n; j++)
          if (array[j] < array[min])
            min = j;
        swap(&array[min], &array[i]);
    }
}

void merge(int array[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = array[l + i];
    for (j = 0; j < n2; j++)
        R[j] = array[m + 1+ j];


    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            array[k] = L[i];
            i++;
        }
        else
        {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        array[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        array[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int array[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;

        mergeSort(array, l, m);
        mergeSort(array, m+1, r);

        merge(array, l, m, r);
    }
}
int partition (int array[], int low, int high)
{
    int pivot = array[high];    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high- 1; j++)
    {

        if (array[j] <= pivot)
        {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

void quickSort(int array[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(array, low, high);

        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

void heapify(int array[], int n, int i)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && array[l] > array[largest])
        largest = l;

    if (r < n && array[r] > array[largest])
        largest = r;


    if (largest != i)
    {
        swap(&array[i], &array[largest]);

        heapify(array, n, largest);
    }
}

void heapSort(int array[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(array, n, i);

    for (int i=n-1; i>=0; i--)
    {

        swap(&array[0], &array[i]);

        heapify(array, i, 0);
    }
}


void printArray(int array[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}


void printChoices()
{
    printf("1. .selectionSort\n");
    printf("2 .insertionSort\n");
    printf("3 .mergeSort\n");
    printf("4 .bubbleSort\n");
    printf("5 .quickSort\n");
    printf("6 .heapSort\n");


}

int main(int argc, char const *argv[]) {

   int array[RANGE]  , i  , choice;
   time_t t;
   srand((unsigned) time(&t));
   for ( i = 0 ; i < RANGE ; i++)
   {
     array[i] =  rand() % 255  ;

   }

   printArray(array,RANGE);

    do {
       printf("\n");
       printChoices();
       printf("Choice :");
       scanf("%d",&choice);

       switch (choice) {
         case 1: selectionSort(array,RANGE); printArray(array,RANGE); break;
         case 2: insertionSort(array,RANGE); printArray(array,RANGE); break;
         case 3: mergeSort(array,0,RANGE);   printArray(array,RANGE); break;
         case 4: bubbleSort(array,RANGE);    printArray(array,RANGE); break ;
         case 5: quickSort(array,0,RANGE);   printArray(array,RANGE); break;
         case 6: heapSort(array,RANGE);      printArray(array,RANGE); break;
         case 7: break;
       }
    } while(choice != 7);



  return 0;
}