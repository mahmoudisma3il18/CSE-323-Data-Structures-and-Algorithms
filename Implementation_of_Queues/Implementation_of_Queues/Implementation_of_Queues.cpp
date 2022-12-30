// Implementation_of_Queues.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

#define MAX_SIZE  100


class Node {
private:
    int data; // Holds data of linked list
    Node* next; // Pointer to next node

public:
    Node(int data) {
        this->data = data;
        this->next = nullptr; // Sets tail to Null
    }

    void setNext(Node* next) {
        this->next = next;
    }

    Node* getNext() {
        return this->next;
    }


    friend class QueueByLinkedList; // Class QueueByLinkedList can use private memebers

};

class Queue {
private:
    int rear, front , size;
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

class QueueByLinkedList {
private : 
    Node* front;
    Node* rear;

public:
    QueueByLinkedList() {
        front = rear = NULL;
    }

    void enQueue(int number_to_be_pushed) {

        Node *new_node = new Node(number_to_be_pushed);

        if (rear = NULL)
        {
            front = rear = new_node;
            return;
        }
        else
        {
            rear->next = new_node;
            rear = new_node;
        }

    }

    int deQueue() {
        int result; // Varibale to hold returned data

        if (front == NULL)
            return -1;
        else
        {
            result = front->data;
            front = front->next;
        }

        if (front == NULL) // If we dequqed the last element ,now queue is empty
            rear = NULL;

        return result;
    }
};

int main()
{
    Queue q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    std::cout << "Front: " << q.Front() << std::endl;
    std::cout << "Size: " << q.Size() << std::endl;
    std::cout << "Empty: " << q.isEmpty() << std::endl;
    std::cout << "Dequeue: " << q.deQueue() << std::endl;
    std::cout << "Front: " << q.Front() << std::endl;
    std::cout << "Size: " << q.Size() << std::endl;
    std::cout << "Empty: " << q.isEmpty() << std::endl;
}

