#include <iostream>
#include <vector>
#include <stack>

// Definition for a Node.
class Node
{
public:
	int val;
	std::vector<Node *> children;

	Node() {}

	Node(int _val)
	{
		val = _val;
	}

	Node(int _val, std::vector<Node *> _children)
	{
		val = _val;
		children = _children;
	}
};

class Solution
{
public:
	inline std::vector<int> &preorder(Node *root)
	{
		// method 1: recursion
		// runtime: 21ms

		// recur(root);
		// return res;

		// method 2: using stack and looping
		// runtime: 27ms

		std::stack<Node *> s;
		s.push(root);

		while (!s.empty())
		{
			const auto x = s.top();
			s.pop();
			if (x)
			{
				res.emplace_back(x->val);
				for (int i = x->children.size() - 1; i >= 0; i--)
					s.push(x->children[i]);
			}
		}

		return res;
	}

private:
	std::vector<int> res;

	// this is for method 1
	inline void recur(Node *node)
	{
		if (!node)
			return;
		res.emplace_back(node->val);
		for (const auto child : node->children)
			recur(child);
	}
};

int main()
{
	Solution s;
	Node *root = new Node(1);
	root->children.emplace_back(new Node(2));
	root->children.emplace_back(new Node(3));
	root->children[0]->children.emplace_back(new Node(4));
	const auto res = s.preorder(root);

	// printing
	for (const auto x : res)
	{
		std::cout << x << ", ";
	}
	std::cout << std::endl;
	return 0;
}