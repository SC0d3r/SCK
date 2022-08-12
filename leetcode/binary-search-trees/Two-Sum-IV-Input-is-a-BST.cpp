#include <iostream>

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
	inline bool findTarget(TreeNode *root, const int &k)
	{
		return search(root, root, k);
	}

private:
	inline bool search(TreeNode *root, TreeNode *node, const int &k)
	{
		if (!node)
			return false;

		return exists(root, node, k - node->val) ||
					 search(root, node->left, k) ||
					 search(root, node->right, k);
	}

	inline bool exists(TreeNode *root, TreeNode *excludeNode, const int &target)
	{
		if (!root)
			return false;
		if (root->val == target && root != excludeNode)
			return true;

		if (target > root->val)
			return exists(root->right, excludeNode, target);
		return exists(root->left, excludeNode, target);
	}
};

int main()
{
	TreeNode *root = new TreeNode(5);
	root->left = new TreeNode(3);
	root->right = new TreeNode(6);

	root->left->left = new TreeNode(2);
	root->left->right = new TreeNode(4);

	root->right->right = new TreeNode(7);

	Solution s;
	std::cout << "res: " << s.findTarget(root, 9) << std::endl;
	return 0;
}