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
	inline TreeNode *insertIntoBST(TreeNode *root, const int &val)
	{
		if (!root)
			return new TreeNode(val);

		insert(root, val);
		return root;
	}

private:
	inline void insert(TreeNode *node, const int &val)
	{
		if (!node)
			return;

		if (val > node->val)
		{
			if (!node->right)
			{
				node->right = new TreeNode(val);
				return;
			}
			return insert(node->right, val);
		}

		if (val < node->val)
		{
			if (!node->left)
			{
				node->left = new TreeNode(val);
				return;
			}
			return insert(node->left, val);
		}
	}
};

int main()
{
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);

	Solution s;
	const auto res = s.insertIntoBST(root, 4);
	std::cout << "node(4)->val: " << root->right->right->val << std::endl;
	return 0;
}