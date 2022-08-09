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
	std::vector<int> inorderTraversal(TreeNode *root)
	{
		if (!root)
			return {};

		std::vector<int> res;
		inorder(res, root);
		return res;
	}

	inline void inorder(std::vector<int> &res, TreeNode *n)
	{
		if (!n)
			return;
		inorder(res, n->left);
		res.emplace_back(n->val);
		inorder(res, n->right);
	}
};

int main()
{
	TreeNode *root = new TreeNode(1);
	root->right = new TreeNode(2);
	root->right->left = new TreeNode(3);

	Solution s;
	const auto res = s.inorderTraversal(root);

	// printing
	for (const auto x : res)
	{
		std::cout << x << ", ";
	}
	std::cout << std::endl;
	return 0;
}