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
	inline bool hasPathSum(TreeNode *root, int targetSum)
	{
		if (!root)
			return false;

		const auto isLeaf = root->left == nullptr && root->right == nullptr;
		if (isLeaf)
			return root->val == targetSum;

		return recur(root, 0, isLeaf, targetSum);
	}

	inline bool recur(TreeNode *root, int tillNow, bool isLeaf, const int &targetSum)
	{
		if (!root)
			return isLeaf && tillNow == targetSum;

		tillNow += root->val;
		const auto isThisLeaf = root->left == nullptr && root->right == nullptr;
		if (isThisLeaf && tillNow == targetSum)
		{
			return true;
		}

		return recur(root->left, tillNow, isThisLeaf, targetSum) ||
					 recur(root->right, tillNow, isThisLeaf, targetSum);
	}
};

int main()

{
	Solution s;
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	// root->right = new TreeNode(3);

	// root->left->left = new TreeNode(3);
	// root->left->right = new TreeNode(4);

	std::cout << "has: " << s.hasPathSum(root, 1) << std::endl;
	return 0;
}