/*
Author : Mahmoud Ismail
Date : 11/10/2022
*/
#include <iostream>

using namespace std;

long factorialRecursive(int n)
{
    if (n==0)
        return 1;
    long m = factorialRecursive(n-1);
    m = m * n;
    return m ;
}

int main()
{
    cout << factorialRecursive(5) << endl;
    return 0;
}
