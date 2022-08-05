#include <iostream>
#include <vector>

// Definition for a Node.
class Node
{
public:
	int val;
	Node *left;
	Node *right;
	Node *next;

	Node() : val(0), left(NULL), right(NULL), next(NULL) {}

	Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

	Node(int _val, Node *_left, Node *_right, Node *_next)
			: val(_val), left(_left), right(_right), next(_next) {}
};

void print(Node *n)
{
	if (n == nullptr)
	{
		// std::cout << "^";
		return;
	}

	std::cout << n->val << ", ";
	if (!n->next)
		std::cout << "#, ";

	print(n->left);

	print(n->right);
}

class Solution
{
public:
	inline Node *connect(Node *root)
	{
		if (!root)
			return nullptr;
		if (!root->left)
			return root;

		// method 1:
		// runtime: 16ms faster than 97% of submissions
		backtrack(root);
		return root;
	}

private:
	inline void backtrack(Node *node)
	{
		if (!node->left)
			return; // this determines if a node is a parent or not

		// if its a parent
		node->left->next = node->right;
		if (node->next)
			node->right->next = node->next->left;

		backtrack(node->left);
		backtrack(node->right);
	}
};

int main()
{
	Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);

	print(root);
	std::cout << std::endl;

	Solution s;
	const auto res = s.connect(root);
	print(res);
	std::cout << std::endl;
	std::cout << std::endl;
	return 0;
}