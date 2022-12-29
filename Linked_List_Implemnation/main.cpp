#include <iostream>

using namespace std;

class Node {
   private :
       int data; // Holds data of linked list
       Node * next; // Pointer to next node

   public:
    Node(int data){
        this->data = data;
        this->next = nullptr; // Sets tail to Null
    }

    void setNext(Node * next){
        this->next = next;
    }

    Node * getNext(){
        return this->next;
    }

    friend class LinkedList;

};

class LinkedList {

private :
    Node * head;  // Pointer to start of LinkedList
public:
    LinkedList(){
    head = nullptr;
    }

    bool empty(){
        if (head == nullptr)
            return true;
        else
            return false;
    }

    int length () {
        int length_of_linked_list = 0;
        Node * current_node = head; // Sets another pointer to head
        while(current_node != nullptr)
        {
            length_of_linked_list++; // Increments size
            current_node = current_node->next; // Points to next element
        }

        return length_of_linked_list; // return size of the list
    }

    void pushFront(int d) {
        Node * new_node = new Node(d); // Creates new node

        new_node->next = head; // sets pointer to next node

        head = new_node ; // Sets start of head

    }

    void popFront() {
        if(empty())
            return;

        Node * node_to_be_deleted = head; // assign head to another pointer

        head = node_to_be_deleted->next;

        delete node_to_be_deleted; // Delete node

    }

    void pushBack(int d) {
        if(empty())
            pushFront(d);

        Node * to_be_inserted = new Node(d); // Creates new node
        Node * current = head;

        while(current->next != nullptr) // Loop until reach last element in linked list
            current = current->next;

        current->next = to_be_inserted; // Set Pointer of pre last node
    }

    void popBack() {
        Node * node_to_be_deleted = nullptr;
        Node * current_ptr = head;
        if(empty())
            return;
        else if (current_ptr->next == nullptr) // if it only contains 1 element
        {
            delete head;
            head = nullptr;
            return;
        }

        while(current_ptr->next->next != nullptr )
            current_ptr = current_ptr->next;

         node_to_be_deleted = current_ptr->next;
         current_ptr->next = nullptr;
         delete node_to_be_deleted;
    }

    void print() {
        Node * current_ptr = head;

        cout<<"Head-->";

        while(current_ptr != nullptr)
        {
            cout<<current_ptr->data<<"-->";
            current_ptr = current_ptr->next;
        }

        cout<<"Tail"<<endl;
    }

    void print_reverse(Node * head)
    {
        if(head == nullptr)
            return;
        print_reverse(head->next);
        cout<<head->data<<"-->";

    }

    void print_reverse(){
        print_reverse(head);
    }


    bool cointains (int d) {
        Node * current_ptr = head;

        while(current_ptr != nullptr)  // Loops until end of list
        {
            if(d == current_ptr->data) // Return true if number exist in list
                return true;
        }

        return false;
    }


    void clear () {
        if(!empty())
            popFront();
    }


    ~LinkedList() { // Destructor
        clear();
    }

    void selectionSort() {

        Node * first_element = head;

        while(first_element != nullptr)
        {
            Node * minimum_node = first_element; // Sets minimum data as first element
            Node * ptr = first_element->next; // Start for element after first

            while(ptr != nullptr)
            {
                if(minimum_node->data > ptr->data) // If there is element less than minimum ,it will be the new minimum
                    minimum_node = ptr;
                ptr=ptr->next;
            }

            int temp = minimum_node->data; //Swap between values
            minimum_node->data = first_element->data; //Swap between values
            first_element->data = temp; //Swap between values


            first_element = first_element->next;
        }
    }

    void bubbleSort() {

        int length_of_list = length(); // Gets number of element in list

        while(length_of_list--) // Loops length of list
        {
            Node * current_ptr = head; // Sets start of list

            while(current_ptr) // Loops until end of list
            {
                if((current_ptr->next) && (current_ptr->data > current_ptr->next->data)) // if current is greater than next swap them and also checks if next is not null
                {
                    int temp = current_ptr->data;
                    current_ptr->data = current_ptr->next->data;
                    current_ptr->next->data = temp;
                }

                current_ptr = current_ptr->next;
            }
        }
    }

    void bubbleSort2 () {
        int length_of_list = length(); // Gets number of element in list

        bool sorted ;

        while(length_of_list--) // Loops length of list
        {
            Node * current_ptr = head; // Sets start of list

            sorted = true;

            while(current_ptr) // Loops until end of list
            {
                if((current_ptr->next) && (current_ptr->data > current_ptr->next->data)) // if current is greater than next swap them and also checks if next is not null
                {
                    int temp = current_ptr->data;
                    current_ptr->data = current_ptr->next->data;
                    current_ptr->next->data = temp;
                    sorted = false;
                }

                current_ptr = current_ptr->next;
            }

            if(sorted)
                return;

        }

    }


};

int main()
{
    LinkedList x;
    x.pushFront(5);
    x.pushFront(3);
    x.pushFront(10);
    x.bubbleSort2();
    x.print();

    return 0;
}
