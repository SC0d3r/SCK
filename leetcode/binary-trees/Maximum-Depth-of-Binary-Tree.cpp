#include <iostream>
#include <vector>

// Definition for a binary tree node.
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
	inline int maxDepth(TreeNode *root)
	{
		return recur(root);
	}

	inline int recur(TreeNode *node)
	{
		if (!node)
			return 0;

		const auto left = 1 + recur(node->left);
		const auto right = 1 + recur(node->right);
		return std::max(left, right);
	}
};

int main()
{
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(3);
	root->right = new TreeNode(3);
	root->right->left = new TreeNode(3);
	root->right->right = new TreeNode(3);
	Solution s;
	std::cout << "depth: " << s.maxDepth(root) << std::endl;
	return 0;
}