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
	std::vector<int> preorderTraversal(TreeNode *root)
	{
		if (!root)
			return {};

		std::vector<int> res;
		preorder(res, root);
		return res;
	}

	inline void preorder(std::vector<int> &res, TreeNode *n)
	{
		if (!n)
			return;
		res.emplace_back(n->val);
		preorder(res, n->left);
		preorder(res, n->right);
	}
};

int main()
{
	TreeNode *root = new TreeNode(1);
	root->right = new TreeNode(2);
	root->right->left = new TreeNode(3);

	Solution s;
	const auto res = s.preorderTraversal(root);

	// printing
	for (const auto x : res)
	{
		std::cout << x << ", ";
	}
	std::cout << std::endl;
	return 0;
}