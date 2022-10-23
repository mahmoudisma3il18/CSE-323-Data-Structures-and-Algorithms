#include <iostream>
#include <stdio.h>
using namespace std;

/*---------------------- Definitions ----------------------------*/

#define TRUE       1
#define FALSE      0


/*------------------- Global Varibales --------------------------*/

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

int main()
{
createArrayDynamic();

    return 0;
}
