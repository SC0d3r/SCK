#include <iostream>
#include <vector>
#include <queue>

//  Definition for a binary tree node.
struct TreeNode;

// utils for printing the tree and see the result
std::vector<std::vector<int>> elems(TreeNode *node);
void print(TreeNode *node);

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
	inline TreeNode *invertTree(TreeNode *root)
	{
		if (!root)
			return root;

		recur(root);
		return root;
	}

	inline void recur(TreeNode *node)
	{
		if (!node)
			return;

		const auto t = node->left;
		node->left = node->right;
		node->right = t;
		recur(node->left);
		recur(node->right);
	}
};

// approach 2:

// class Solution
// {
// public:
// 	inline TreeNode *invertTree(TreeNode *root)
// 	{
// 		if (!root)
// 			return root;

// 		const auto left = root->left;
// 		root->left = invertTree(root->right);
// 		root->right = invertTree(left);

// 		return root;
// 	}
// };

int main()
{
	Solution s;
	TreeNode *root = new TreeNode(4);
	root->left = new TreeNode(2);
	root->right = new TreeNode(7);

	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(3);

	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(9);

	std::cout << "before reversing" << std::endl;
	print(root);

	std::cout << "after reversing" << std::endl;
	const auto rootOfReversed = s.invertTree(root);
	print(rootOfReversed);

	std::cout << std::endl;
	return 0;
}

// utility functions to print the tree

std::vector<std::vector<int>> elems(TreeNode *node)
{
	std::queue<std::vector<TreeNode *>> q;
	q.push({node});
	std::vector<std::vector<int>> res;

	int i = 0; // this is the level of the tree
	while (!q.empty())
	{
		const auto batch = q.front();
		q.pop();
		std::vector<TreeNode *> newBatch;

		res.push_back({});
		for (const auto b : batch)
		{
			res[i].push_back(b->val);
			if (b->left)
				newBatch.emplace_back(b->left);
			if (b->right)
				newBatch.emplace_back(b->right);
		}

		i++;
		if (newBatch.size())
			q.push(newBatch);
	}

	return res;
}

void print(TreeNode *node)
{
	const auto res = elems(node);
	for (const auto xs : res)
	{
		for (const auto x : xs)
		{
			std::cout << x << ", ";
		}
		std::cout << std::endl;
	}
}