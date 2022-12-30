// Qes-6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>

using namespace std;

string postfixToinfix(string s) { //Dont leave any space between char
    stack <string> stackOfChar;

    for (char c : s)
    {
        if (c == '+' || c == '-' || c == '*' || c == '/') // If its operator it will pop the stack
        {
            string op1 = stackOfChar.top();
            stackOfChar.pop();
            string op2 = stackOfChar.top();
            stackOfChar.pop();
            stackOfChar.push('(' + op2 + c + op1 + ')');
        }
        else
        {
            stackOfChar.push(string(1, c)); // If its digit or number it will be pushed to stack
        }
    }

    return stackOfChar.top();

}

int main()
{
    cout << postfixToinfix("Xy*t+") << endl;
}

