/*
 Author : Mahmoud Ismail
 Date   : 25 / 10 / 2022
*/

/*----------------------------- Includes ------------------------------------------*/
#include <iostream>
#include <stdio.h>
using namespace std;

/*---------------------------------- Definitions -------------------------------------*/
#define FALSE      0
#define TRUE       1

/*------------------------------------- Functions ---------------------------------------*/

int binarySearch(int *array,int number,int low,int high)// Using Recursive Method , and array must be sorted
{
    int mid;

    if(low > high)
        return -1; // Return -1 if index is wrong

    mid = (high + low) / 2 ;
    if(number == array[mid])
            return mid;
    else if (number<array[mid])
        binarySearch(array,number,low,mid-1);
    else if (number > array[mid])
        binarySearch(array,number,mid+1,high);
    else
        return -1;// Return -1 if number doesn't exist

}

int binarySearch1(int *array,int number,int low,int high)// Using Iteration Method , and array must be sorted
{
    int mid ;

    while(high >= low){
        mid = (high + low) / 2;

        if(number == array[mid])
            return mid;
        else if (number < array[mid])
            high = mid -1;
        else if (number > array[mid])
            low = mid + 1;
    }

    return -1; //if number doesnt exist or high < low it will return -1
}
int main()
{
    int array[] = {4,5,6,7,8,9};
    int index = binarySearch(array,2,0,5);

    if(index == -1)
        cout<<"Number doesnt exist";
    else
    cout<<"Number 5 is found at index : "<<index;
    return 0;
}
