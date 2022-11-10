/*
Author : Mahmoud Ismail
Date : 11/10/2022
*/
#include <iostream>

using namespace std;

int minArrayRecursive(int *array,int start,int end)
{
    if(start==end)
        return array[start];
    int mid = (start + end) / 2;
    int min1 = minArrayRecursive(array,start,mid);
    int min2 = minArrayRecursive(array,mid+1,end);

    if(min1<=min2)
        return min1;
    else
        return min2;
}

int main()
{
    int array[]={1,8,0,-5};
    cout << "Min of array : "<< minArrayRecursive(array,0,3)<< endl;
    return 0;
}
