#include <iostream>
#include <cstdlib>

using namespace std;

class Node
{
public:
	string data;

	Node* next;

	Node* left;

	Node* right;

	Node(string data) {
		this->data = data;
		this->right = NULL;
		this->left = NULL;
	};

	bool isNumeric() {
		for (auto c : data)
		{
			if (!(c >= '0' && c <= '9'))
				return false;
		}

		return true;
	}

	int toNumeric() {
		return atoi(data.c_str());
	}


private:
};

int eval(int left_operand, int right_operand, string oper) {
	if (oper == "+")
		return left_operand + right_operand;
	else if (oper == "-")
		return left_operand - right_operand;

	return 0;

}

int evaluate(Node* subtree) {
	if (subtree->isNumeric())
		return (subtree->toNumeric());
	int left_subtree = evaluate(subtree->left);
	int right_subtree = evaluate(subtree->right);

	return eval(left_subtree, right_subtree, subtree->data);
}


void inorderTraversal(Node* node) {
	if (node == NULL)
		return;
	inorderTraversal(node->left);
	cout << node->data;
	inorderTraversal(node->right);
}

void preorderTraversal(Node* node) {
	if (node == NULL)
		return;
	cout << node->data;
	preorderTraversal(node->left);
	preorderTraversal(node->right);
}

void postorderTraversal(Node* node) {
	if (node == NULL)
		return;
	postorderTraversal(node->left);
	postorderTraversal(node->right);
	cout << node->data;
}


int main()
{
	Node* n1 = new Node("+");
	Node* n2 = new Node("5");
	Node* n3 = new Node("8");
	n1->left = n2;
	n1->right = n3;

	cout << "Inorder : ";
	inorderTraversal(n1);
	cout << endl;

	cout << "Preorder : ";
	preorderTraversal(n1);
	cout << endl;

	cout << "Postorder : ";
	postorderTraversal(n1);
	cout << endl;

	cout<<evaluate(n1)<<endl;


}

