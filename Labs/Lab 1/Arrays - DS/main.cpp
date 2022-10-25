/*
 Author : Mahmoud Ismail
 Date   : 25/10/2022
*/

#include <iostream>

using namespace std;


int* reverseArray(int a_count, int* a, int* result_count) {

    int i=0,j = (a_count-1),temp = 0; // Counters for array;
    *result_count = a_count; // Number of elements in array
    while(i<j){
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        i++;
        j--;
    }

    return a;

}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
