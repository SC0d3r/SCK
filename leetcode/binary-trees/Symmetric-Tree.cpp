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
	bool isSymmetric(TreeNode *root)
	{
		return recur(root->left, root->right);
	}

	inline bool recur(TreeNode *left, TreeNode *right)
	{
		if (!left && !right)
			return true;

		if (left && !right)
			return false;
		if (right && !left)
			return false;

		if (left->val != right->val)
			return false;

		return recur(left->left, right->right) &&
					 recur(left->right, right->left);
	}
};

int main()
{
	Solution s;
	TreeNode *symTree = new TreeNode(1);

	symTree->left = new TreeNode(2);
	symTree->right = new TreeNode(2);

	symTree->left->left = new TreeNode(3);
	symTree->left->right = new TreeNode(4);

	symTree->right->left = new TreeNode(3);
	symTree->right->right = new TreeNode(4);

	TreeNode *nonSymTree = new TreeNode(1);

	nonSymTree->right = new TreeNode(2);
	nonSymTree->right->left = new TreeNode(3);

	// nonSymTree->left->right = new TreeNode(3);
	// nonSymTree->left->right = new TreeNode(4);

	// std::cout << "(sym tree) is sym: " << (s.isSymmetric(symTree) ? "True" : "False") << std::endl;
	std::cout << "(non sym tree) is sym: " << (s.isSymmetric(nonSymTree) ? "True" : "False") << std::endl;

	return 0;
}