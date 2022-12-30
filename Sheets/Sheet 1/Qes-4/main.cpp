/*
 Author : Mahmoud Ismail
 Date   : 24/10/2022
*/

/*------------------------------- Includes -------------------------------------*/
#include <iostream>
#include <stdio.h>


using namespace std;

/*-------------------------- Global Variables ---------------------------------*/

float *g_dynamicArray = NULL;

/*------------------------- Functions ----------------------------------------*/

int factorial(int num) // Returns factorial of number
{
    int result = 1 ;
    while(num > 0)
    {
        result *= num;
        num--;

    }
    return result;
}

void createDynamicArray(void) // Creates Dynamic float array and prints sum of it
{
    int sizeOfArray = 0;
    float sumOfArray = 0;
    cout<<"Enter Size of Array: ";
    cin>>sizeOfArray;

    g_dynamicArray = new float [sizeOfArray]; // Creates the array

    for(int i = 0 ; i < sizeOfArray ; i++)
        g_dynamicArray[i] = (1.0/factorial(i));  //Fill elemnts of array

    for(int i = 0 ;i<sizeOfArray;i++)
        sumOfArray += g_dynamicArray[i];  //Calculate sum of the array

     cout<<"Sum of array is : "<<sumOfArray<<endl;
}


int main()
{
    createDynamicArray();

    delete [] g_dynamicArray; //Free the array
    return 0;
}
