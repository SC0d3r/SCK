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
	inline int sumOfLeftLeaves(TreeNode *root)
	{
		if (isLeaf(root))
			return 0;

		const auto res = recur(root, false);
		return res;
	}

private:
	inline int recur(TreeNode *node, bool isLeft)
	{
		if (!node)
			return 0;
		if (isLeft && isLeaf(node))
			return node->val;

		return recur(node->left, true) + recur(node->right, false);
	}

	inline bool isLeaf(TreeNode *node)
	{
		return node && !node->left && !node->right;
	}
};

int main()
{
	TreeNode *root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);

	Solution s;
	std::cout << "ans: " << s.sumOfLeftLeaves(root) << std::endl;
	return 0;
}