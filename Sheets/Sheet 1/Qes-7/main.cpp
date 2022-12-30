/*
  Author : Mahmoud Ismail
  Date   : 24/10/2022
*/


/*-------------------------------------- Includes ------------------------------------*/
#include <iostream>
#include <stdio.h>

using namespace std;

/*------------------------------------- Definitions -----------------------------------*/

#define SIZE_OF_ARRAY     5
#define TRUE              1
#define FALSE             0

/*-------------------------------------- Functions ------------------------------------*/

void swap(int *x,int *y) // Function to swap elements of array
{
    int temp = *x;
    *x = *y ;
    *y = temp;
}

void bubbleSort(int *array,int sizeOfArray) // To sort the array in ascending order ,Time Complexity O(n^2)
{
    for(int i = 0 ; i < sizeOfArray -1 ; i++)
        for(int j = 0 ; j < sizeOfArray - i - 1;j++)
    {
        if(array[j] > array[j+1])
            swap(&array[j],&array[j+1]);
    }
}

void bubbleSort2(int *array,int sizeOfArray) // To sort the array in ascending order but it takes less time
{
    bool sorted ;

    for(int i = 0 ; i < sizeOfArray -1 ; i++)
        {
            sorted = TRUE;
            for(int j = 0 ; j < sizeOfArray - i - 1 ; j++)
            {
                if(array[j] > array[j+1])
                {
                    swap(array[j],array[j+1]);
                    sorted = FALSE;
                }
            }

            if(sorted)
                return;
        }
}

void printArray(int *array,int sizeOfArray)
{
    for(int i = 0 ; i < sizeOfArray ; i++)
        cout<<array[i]<<"\t";

    cout<<endl;

}

int main()
{
    int array[SIZE_OF_ARRAY] = {1,5,3,4,5};
    printArray(array,SIZE_OF_ARRAY);
    bubbleSort2(array,SIZE_OF_ARRAY);
    printArray(array,SIZE_OF_ARRAY);
    return 0;
}
