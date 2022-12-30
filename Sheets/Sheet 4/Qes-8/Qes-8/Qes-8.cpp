// Qes-8.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include <iostream>

#define MAX_SIZE 1000

using namespace std;


class Queue {
private:
    int rear, front, size;
    int data[MAX_SIZE];

public:
    Queue()
    {
        rear = 0;
        front = 0;
        size = 0; // Size of queue
    }

    void enQueue(int number_to_be_entered) {
        if (size == MAX_SIZE) // check if queue is full
            cout << "Queue is full" << endl;
        else
        {
            data[rear] = number_to_be_entered; // Put data in array
            rear++;
            size++;
        }
    }

    int deQueue() {

        int result;

        if (size == 0) // Check if queue is empty
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        else
        {
            result = data[front];
            front++;
            size--; // When we dequeue size decreses
        }

        return result;

    }

    int Front() {
        if (size == 0)
        {
            cout << "Queue is Empty" << endl;
            return -1;
        }
        else
            return data[front]; // Return first element inserted (FIFO)
    }

    int Size() {
        return size;
    }

    bool isEmpty() {
        return (size == 0);
    }

};

void jobStataics(Queue q1) {
    int total_time_job = 0;
    int average_time_job = 0;
    int sizeOfQueue = q1.Size();

    for (int i = 0; i < sizeOfQueue; i++)
    {
        total_time_job = total_time_job +  q1.deQueue();
    }

    cout << "Total Time : " << total_time_job << endl;
    cout << "Average Time : " << total_time_job / sizeOfQueue<<endl;
}


int main()
{
    Queue q1;
    q1.enQueue(4);
    q1.enQueue(3);
    q1.enQueue(4);
    q1.enQueue(3);
 

   /* cout << q1.deQueue() << endl;
    cout << q1.deQueue() << endl;
    cout << q1.deQueue() << endl;
    cout << q1.deQueue() << endl;
    */
    jobStataics(q1);

}


