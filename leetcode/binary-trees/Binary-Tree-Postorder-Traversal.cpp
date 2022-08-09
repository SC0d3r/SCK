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
	std::vector<int> res;
	inline std::vector<int> &postorderTraversal(TreeNode *root)
	{
		postorder(res, root);
		return res;
	}

private:
	inline void postorder(std::vector<int> &res, TreeNode *n)
	{
		if (!n)
			return;

		postorder(res, n->left);
		postorder(res, n->right);
		res.emplace_back(n->val);
	}
};

int main()
{
	TreeNode *root = new TreeNode(1);
	root->right = new TreeNode(2);
	root->right->left = new TreeNode(3);

	Solution s;
	const auto res = s.postorderTraversal(root);

	for (const auto x : res)
	{
		std::cout << x << ", ";
	}
	std::cout << std::endl;

	return 0;
}
