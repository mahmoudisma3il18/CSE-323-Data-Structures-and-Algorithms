/*
Author : Mahmoud Ismail
Date   : 11/9/2022
*/

#include <iostream>
#include <stdio.h>

using namespace std;

#define SIZE_OF_ARRAY   5

void swap (int * n1,int * n2) // to swap between 2 arrays
{
    int temp ;
    temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

void printArray(int * array) // to print array
{
    for(int i = 0 ; i<SIZE_OF_ARRAY;i++)
        cout << *(array+i) << endl;

}

void selectionSort(int * array)
{
    int min_index;
    for(int i = 0 ;i < SIZE_OF_ARRAY - 1 ;i++) // to loop size of array - 1
    {
        min_index = i;

        for(int j = i+1;j<SIZE_OF_ARRAY;j++)
            if(array[j]<array[min_index]) // to get minimum number
            min_index = j;

        if(min_index != i)
            swap(&array[i],&array[min_index]);

    }
}

using namespace std;

int main()
{
    int array[] = {100,5,8,99,23};
    selectionSort(array);
    printArray(array);
    return 0;
}
