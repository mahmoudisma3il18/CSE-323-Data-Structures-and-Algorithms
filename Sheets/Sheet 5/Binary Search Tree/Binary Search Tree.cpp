#include <iostream>
#include <iomanip>

using namespace std;

class Node {
public:

    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* search(Node* root, int data) {
    if ((root == NULL) || root->data == data)
        return root;

    else if ((data) < (root->data))
        return search(root->left, data);

    else if ((data) > root->data)
        return search(root->right, data);

    else 
        return NULL;
}

Node* insert(Node* root, int value) {

    if (root == NULL)
        return new Node(value);

     if (value <= root->data)
        root->left = insert(root->left, value);

    else 
        root->right = insert(root->right, value);

   
        return root;

}

Node* minValue(Node* node) {
    Node* current = node;

    while (current->left != NULL)
        current = current->left;

    return current;
}

Node* deleteNode(Node* root, int data) {
    if (root == NULL)
        return root;

    if (data < root->data)
    {
        root->left = deleteNode(root->left, data);
    }

    else if (data > root->data)
    {
        root->right = deleteNode(root->right, data);
    }

    else
    {
        if (root->left == NULL)
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        else if (root->right == NULL)
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = minValue(root->right); // Get minimum value in right branch
        root->data = temp->data; // 3amalt copy ll minimum number fy l root
        root->right = deleteNode(root->right, temp->data);

    }

    return root;
}


void print_tree(Node* root, int indent = 0)
{
    if (root != nullptr)
    {
        if (root->right)
        {
            print_tree(root->right, indent + 4);
        }
        if (indent)
        {
            std::cout << std::setw(indent) << ' ';
        }
        if (root->right)
        {
            std::cout << " /\n" << std::setw(indent) << ' ';
        }
        std::cout << root->data << "\n ";
        if (root->left)
        {
            std::cout << std::setw(indent) << ' ' << " \\\n";
            print_tree(root->left, indent + 4);
        }
    }
}

int treeMax(Node* root) {
    if (root->right == NULL)
        return root->data;
    treeMax(root->right);
}

int treeMin(Node* root) {
    if (root->left == NULL)
        return root->data;
    treeMin(root->left);
}

int main()
{
    
    Node* n1 = new Node(6);

    Node* temp = insert(n1, 8);

    temp = insert(n1, 4);

    temp = insert(n1, 10);

    temp = insert(n1, 9);

    temp = insert(n1, 1);

    temp = insert(n1, 5);

    temp = deleteNode(n1, 1);
     /*
    temp = search(n1,8);

    if (temp == NULL)
        cout << "Node doesnt exist" << endl;
    else
        cout << temp->data << endl;

    print_tree(n1);

     */

    cout << "Min : " << treeMin(n1) << endl;




}

