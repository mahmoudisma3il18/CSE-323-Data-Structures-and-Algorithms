#include <iostream>
#include <cassert>
#include <vector>
#include <stack>
#include <list>

using namespace std;

class Stack // Create stack class
{
public:
	Stack() {
		size = 0;
	};

	int peek() { // Return last item pushed in stack
		assert(size > 0);
		return array[size-1];
	}

	void push(int number_to_be_pushed) { // Pushes new item to stack
		assert(size < 1000);
		array[size] = number_to_be_pushed;
		size++;
	}

	void pop() { // Pops the stack
		assert(size > 0);
		size--;
	}

	bool isEmpty() { // Return true if stack is empty
		return (size == 0);
	}

	bool isFull() { // Return true if stack is full
		return (size == 999);
	}

	bool isEqaul(Stack s) { //Problem with this function that it changes the values of stack in caller object


		while (!isEmpty() && !s.isEmpty())
		{
			if (peek() != s.peek())
				return false;
			pop();
			s.pop();
		}

		return (isEmpty() && s.isEmpty());

	}

	bool isEqaul2(Stack s2) {

		Stack s1 = *this; // Copy the values and dont change it

		while (!s1.isEmpty() && !s2.isEmpty())
		{
			if (s1.peek() != s2.peek())
				return false;
			s1.pop();
			s2.pop();
		}

		return (s1.isEmpty() && s2.isEmpty());

	}

	bool isEqaul3(Stack s2) {
		Stack temp_stack;

		while (!isEmpty() && !s2.isEmpty())
		{
			if (peek() == s2.peek())
			{
				temp_stack.push(peek());
				pop();
				s2.pop();
			}
			else
			{
				while (!temp_stack.isEmpty())
				{
					push(temp_stack.peek());
					temp_stack.pop();
				}
				return false;
			}
		}

		bool stack_is_empty = isEmpty() && s2.isEmpty();

		while (!temp_stack.isEmpty())
		{
			push(temp_stack.peek());
			temp_stack.pop();
		}

		return stack_is_empty;
	}

private:
	int array[1000] ;
	int size;
};

class StackInLinkedList
{
public:
	StackInLinkedList();
	

private:
	
};

StackInLinkedList::StackInLinkedList()
{
}

StackInLinkedList::~StackInLinkedList()
{
}


vector <int> removedReaptedItems(vector <int> & arr)
{
	stack<int> s;

	for (size_t i = 0; i < arr.size(); i++)
	{
		if (s.empty() || (s.top() != arr[i]))
		{
			s.push(arr[i]);
		}
	}

	vector <int> arr_result(s.size());

	for (size_t i = 0; i < arr_result.size(); i++)
	{
		arr_result[arr_result.size() - i - 1] = s.top();
		s.pop();
	}

	return arr_result;

}



int main()
{

	vector<int> arr = { 1, 1, 2, 2, 3, 4, 4, 5 };
	vector<int> result = removedReaptedItems(arr);
	for (int i = 0; i < result.size(); i++)
		cout << result[i];
	
	return 0;

	Stack s1,s2;
	s1.push(5);
	s1.push(2);
	s2.push(5);
	s2.push(2);
	//s2.push(3);


	cout << s1.peek()<<" x  " << s1.isEqaul3(s2) << endl;
}

