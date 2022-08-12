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
	inline TreeNode *searchBST(TreeNode *root, const int &val)
	{
		if (!root)
			return root;
		if (root->val == val)
			return root;
		if (root->val < val)
			return searchBST(root->right, val);
		else
			return searchBST(root->left, val);
	}
};

int main()
{
	TreeNode *root = new TreeNode(4);
	root->left = new TreeNode(2);
	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(3);
	root->right = new TreeNode(7);

	Solution s;
	const auto ans = s.searchBST(root, 2);

	std::cout << "node: " << ans->val << std::endl;
	return 0;
}