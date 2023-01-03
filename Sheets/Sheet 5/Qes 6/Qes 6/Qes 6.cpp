#include <iostream>
#include <cstring>

using namespace std;

class Node
{
public:
	string tagName;
	string tagValue;

	Node* childeren[100] ;

	Node(string tagName,string tagValue) {
		this->tagName = tagName;
		this->tagValue = tagValue;
		memset(childeren, 0, sizeof(childeren));
	}
private:
};

void TreetoXML(Node* node) {
	if (node == NULL)
		return;
	cout << "<" << node->tagName << ">" << endl;
	cout << node->tagValue << endl;
	for (int i = 0; i < 100; i++)
	{
		if (node->childeren[i] != NULL)
			TreetoXML(node->childeren[i]);
	}
	cout << "</" << node->tagName << ">" << endl;
}

int main()
{
	Node* root = new Node{ "root", "rootvalue" };

	// Create some child nodes
	Node* child1 = new Node{ "child1", "child1value" };
	Node* child2 = new Node{ "child2", "child2value" };

	root->childeren[0] = child1;
	root->childeren[1] = child2;

	TreetoXML(root);
}

