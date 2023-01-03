
#include <iostream>


using namespace std;

class Node
{
public:
	string data;

	Node* left;

	Node* right;

	Node(string data) {
		this->data = data;
		this->right = NULL;
		this->left = NULL;
	};

private:
};

int countLeaves(Node* root) {
	if (root == NULL)
		return 0;
	else if ((root->left == NULL) && (root->right == NULL))
		return 1;

	return countLeaves(root->right) + countLeaves(root->left);
}
int main()
{

	Node* n1 = new Node("1");
	Node* n2 = new Node("5");
	Node* n3 = new Node("8");
	Node* n4 = new Node("9");
	Node* n5 = new Node("4");
	n1->left = n2;
	n1->right = n3;
	n3->left = n4;
	n3->right = n5;
    std::cout << "Count of leaves : "<<countLeaves(n1)<<endl;
}


