#include <iostream>
#include <stdio.h>
using namespace std;

/*---------------------- Definitions ----------------------------*/

#define TRUE       1
#define FALSE      0

#define SIZE_OF_ARRAY  4


/*------------------- Global Variables --------------------------*/

int *g_dynamicArray = NULL;

/*------------------ Functions ---------------------------------*/

/*---------------------------------------------------------------------------
Description : This functions creates a dynamic array of size entered by user
----------------------------------------------------------------------------*/
void createArrayDynamic()
{
    int size = 0,i = 0;
    cout<<"Enter size of array: " ;
    cin>>size;

    g_dynamicArray = new int [size]; // Create dynamic array

    while(i<size)
    {
        cout<<"Enter array["<<i<<"]: ";
        cin>>g_dynamicArray[i];
        i++;
    }
}

/*--------------------------------------------------------------------------
Description : This function prints the array
----------------------------------------------------------------------------*/
void printArray(int *array,int size)
{
    for(int i = 0 ; i < size ; i++)
    cout<<"Array["<<i<<"] = "<<array[i];
}

/*--------------------------------------------------------------------------
Description : Function that takes an array of integers and returns whether it has repeated items
or not.

Solution 1
---------------------------------------------------------------------------------*/
bool isArrayRepeated(int *array,int size) // Time Complexity = O(n^2)
{
    for(int i = 0 ; i < size ; i++ )
        for(int j = 0 ; j < size ; j++)
        if((i != j) && (array[i] == array[j]) )
        return TRUE;

    return FALSE;
}

/*--------------------------------------------------------------------------
Description : Function that takes an array of integers and returns whether it has repeated items
or not.

Solution 2
---------------------------------------------------------------------------------*/

bool isArrayRepeated2(int *array,int size) // Time Complexity = O(n^2) , but less time
{
    for(int i = 0 ; i < size-1 ; i++ )
        for(int j = i+1 ; j < size ; j++)
        if(array[i] == array[j] )
        return TRUE;

    return FALSE;
}

/*--------------------------------------------------------------------------
Description : Function that takes an array of integers and returns whether it has repeated items
or not.

Its only works for sorted arrays

Solution 3
---------------------------------------------------------------------------------*/
bool isArrayRepeated3(int *array,int size) // Time Complexity = O(n)
{
    for(int i = 0 ; i < size -1 ; i++ )
        if(array[i] == array[i+1])
        return TRUE;

    return FALSE;
}

int main()
{
int array[SIZE_OF_ARRAY] = {1,2,4,3};

cout<<isArrayRepeated2(array,SIZE_OF_ARRAY);

    return 0;
}
