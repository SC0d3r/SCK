#include <iostream>

// Definition for a binary tree node.
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
	inline TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
	{
		// method 1:
		// runtime: 27ms

		// if the p value is greater(or lesser) and qvalue is lesser(or greater)
		// then we have found the common ancestor
		const auto val = root->val;
		if (p->val < val && q->val < val)
			return lowestCommonAncestor(root->left, p, q);
		if (p->val > val && q->val > val)
			return lowestCommonAncestor(root->right, p, q);

		return root;

		// method 2:
		// runtime : 25ms

		// direct child
		// if (p->left == q || p->right == q)
		// 	return p;

		// const auto pAnc = findAncestor(root, root, p->val, q->val, nullptr);
		// const auto qAnc = findAncestor(root, root, q->val, p->val, pAnc);

		// if (qAnc == pAnc)
		// 	return pAnc;
		// return lowestCommonAncestor(root, pAnc, qAnc);
	}

private:
	inline TreeNode *findAncestor(TreeNode *root,
																TreeNode *anc,
																const int &pVal,
																const int &otherVal,
																const TreeNode *otherAnc)
	{
		if (root->val == otherVal)
			return root;

		if (root == otherAnc)
			return root;

		if (root->val == pVal)
			return anc;

		if (pVal < root->val)
			return findAncestor(root->left, root, pVal, otherVal, otherAnc);
		return findAncestor(root->right, root, pVal, otherVal, otherAnc);
	}
};

int main()
{
	TreeNode *root = new TreeNode(5);
	root->left = new TreeNode(3);
	root->right = new TreeNode(6);

	root->left->left = new TreeNode(2);
	root->left->right = new TreeNode(4);

	root->left->left->left = new TreeNode(1);

	// root->right->left = new TreeNode(7);
	root->right->right = new TreeNode(9);

	// root->left->right->left = new TreeNode(1);
	// root->left->right->right = new TreeNode(5);

	Solution s;

	const auto res = s.lowestCommonAncestor(root, root->left->right, root->left->left->left);
	// const auto res = s.lowestCommonAncestor(root, root->left->right, root->right->right);
	std::cout << "ans: " << res->val << std::endl;
	return 0;
}