#include <iostream>
#include <stdio.h>

using namespace std;


int findMax(int *array,int size) // Section solution
{
    if(size == 1)
        return array[0];

    return max(findMax(array,size - 1),array[size-1]);
}

int main()
{
    int array[] = {1,2,3,4,10,8};
    cout<<"Max of array is : "<<findMax(array,6);
    return 0;
}
