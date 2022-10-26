/*
 Author : Mahmoud Ismail
 Date   : 26/10/2022
*/

#include <iostream>

using namespace std;

void merge(int *array,int begin,int mid,int end)
{
    int leftArraySize  = mid - begin +1; // calculates left array size
    int rightArraySize = end - mid;      // calculates right array size
    int arrayIndex = begin,leftArrayIndex = 0,rightArrayIndex=0; // array index is where it stopped last time

    int *rightArray = new int[rightArraySize], *leftArray = new int[leftArraySize]; // Creates array dynamic

    for(leftArrayIndex ; leftArrayIndex < leftArraySize;leftArrayIndex++)
        leftArray[leftArrayIndex] = array[begin+leftArrayIndex]; // Fill the merged array with left of array
    for(rightArrayIndex;rightArrayIndex<rightArraySize;rightArrayIndex++)
        rightArray[rightArrayIndex] = array[mid+1+rightArrayIndex]; // Fill the merged array with right of array

    leftArrayIndex = 0;
    rightArrayIndex = 0;

    while((rightArrayIndex < rightArraySize) && (leftArrayIndex < leftArraySize)){ // Loop until one of arrays end
            if (leftArray[leftArrayIndex] <= rightArray[rightArrayIndex]){ // Ascending order
                array[arrayIndex] = leftArray[leftArrayIndex];
                leftArrayIndex++;
            }
            else {
                array[arrayIndex] = rightArray[rightArrayIndex];
                rightArrayIndex++;
            }
       arrayIndex++;
    }

    while(leftArrayIndex < leftArraySize){
        array[arrayIndex] = leftArray[leftArrayIndex];
        arrayIndex++;
        leftArrayIndex++;
    }

    while(rightArrayIndex < rightArraySize){
        array[arrayIndex] = rightArray[rightArrayIndex];
        arrayIndex++;
        rightArrayIndex++;
    }

    delete []leftArray; // Delete arrays
    delete []rightArray;


}

void mergeSort(int *array,int beginOfArray,int endOfArray) // O(nlogn)
{
    if(beginOfArray >= endOfArray) // to check if end is greater
        return;
    int mid = beginOfArray + ((endOfArray - beginOfArray) / 2); // Get mid with respect to array index

    mergeSort(array,beginOfArray,mid); // merge right of array
    mergeSort(array,mid+1,endOfArray); // merge left of array
    merge(array,beginOfArray,mid,endOfArray); // sort array


}

int main()
{
    int array[]={5,100,1,2,3};
    mergeSort(array,0,4);
    for(int i = 0 ; i < 5 ; i++)
        cout<<array[i]<<endl;
    return 0;
}
