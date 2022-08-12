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
	bool isValidBST(TreeNode *root)
	{
		// method 1:
		// we traverse the tree create new bst and compare if they are same or not
		// runtime: 18ms at best run

		// TreeNode *newTree = new TreeNode(root->val);
		// createBST(root, newTree);
		// return areTreesEqual(root, newTree);

		// method 2:
		// go through the tree for each val find its true place and
		// then check if it is in the right place with the same father node or not
		// runtime: 13ms

		return isValid(root, root, nullptr);

		// method 3:
		// there is smarter way of solving this
		// check leetcode
	}

private:
	inline bool isValid(TreeNode *root, TreeNode *node, TreeNode *ancestor)
	{
		if (!node)
			return true;
		const auto father = findFather(root, nullptr, node->val);

		if (ancestor && ancestor != father)
			return false;

		if (
				node->left && node->val <= node->left->val)
			return false;

		if (node->right && node->val >= node->right->val)
			return false;

		return isValid(root, node->left, node) && isValid(root, node->right, node);
	}

	inline TreeNode *findFather(TreeNode *root, TreeNode *ancestor, const int &val)
	{
		if (root->val == val)
			return ancestor;

		if (val < root->val)
		{
			if (!root->left)
				return ancestor;
			return findFather(root->left, root, val);
		}

		if (!root->right)
			return ancestor;
		return findFather(root->right, root, val);
	}

	inline bool areTreesEqual(TreeNode *tree1, TreeNode *tree2)
	{
		if (!tree1 && !tree2)
			return true;
		if (!tree1 && tree2)
			return false;
		if (tree1 && !tree2)
			return false;

		if (tree1->val != tree2->val)
			return false;

		return areTreesEqual(tree1->left, tree2->left) &&
					 areTreesEqual(tree1->right, tree2->right);
	}

	inline void createBST(TreeNode *root, TreeNode *res)
	{
		if (!root)
			return;

		if (root->left)
			insert(res, root->left->val);

		if (root->right)
			insert(res, root->right->val);

		createBST(root->left, res);
		createBST(root->right, res);
	}

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

	// bool recur(TreeNode *node, TreeNode *ancestor)
	// {
	// 	if (!node)
	// 		return true;
	// 	if (
	// 			node->left &&
	// 			(node->val <= node->left->val || ancestor && node->left->val >= ancestor->val))
	// 		return false;

	// 	if (node->right &&
	// 			(node->val >= node->right->val || ancestor && node->right->val <= ancestor->val))
	// 		return false;

	// 	return recur(node->left, root) && recur(node->right, node);
	// }
};

int main()
{
	Solution s;
	TreeNode *root = new TreeNode(3);
	root->left = new TreeNode(1);
	root->right = new TreeNode(5);

	root->left->left = new TreeNode(0);
	root->left->right = new TreeNode(2);

	root->right->left = new TreeNode(4);
	root->right->right = new TreeNode(6);

	// const auto res = s.isValidBST(root);
	// std::cout << "res root val: " << res->val << std::endl;
	// std::cout << "res left tree val: " << res->left->val << std::endl;
	// std::cout << "res right tree val: " << res->right->val << std::endl;
	std::cout
			<< "is a valid(BST): " << s.isValidBST(root) << std::endl;

	return 0;
}