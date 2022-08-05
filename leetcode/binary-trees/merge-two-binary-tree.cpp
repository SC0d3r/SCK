#include <iostream>
#include <vector>

//  Definition for a binary tree node.
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
	inline TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
	{

		// bellow was for method 1;

		// if (root1 == nullptr && root2 == nullptr)
		// return nullptr;
		// TreeNode *merged = new TreeNode();
		// merge(root1, root2, merged);
		// return merged;

		// method 2: writing better code :)
		// runtime: 34ms this one is fast
		if (!root1)
			return root2;
		if (!root2)
			return root1;

		root1->val += root2->val;
		root1->left = mergeTrees(root1->left, root2->left);
		root1->right = mergeTrees(root1->right, root2->right);
		return root1;
	}

private:
	// method 1:
	// runtime: 71ms at best run, seems slow?
	void merge(TreeNode *root1, TreeNode *root2, TreeNode *merged)
	{
		if (root1 == nullptr && root2 == nullptr)
		{
			return;
		}

		if (root1 != nullptr && root2 != nullptr)
		{
			// root2 has val
			merged->val = root1->val + root2->val;
			if (root2->left != nullptr || root1->left != nullptr)
			{
				merged->left = new TreeNode();
				merge(root1 == nullptr ? nullptr : root1->left,
							root2 == nullptr ? nullptr : root2->left, merged->left);
			}

			if (root2->right != nullptr || root1->right != nullptr)
			{
				merged->right = new TreeNode();
				merge(root1 == nullptr ? nullptr : root1->right,
							root2 == nullptr ? nullptr : root2->right, merged->right);
			}
		}

		if (root1 == nullptr)
		{
			// root2 has val
			merged->val = root2->val;
			if (root2->left != nullptr)
			{
				merged->left = new TreeNode();
				merge(nullptr, root2->left, merged->left);
			}

			if (root2->right != nullptr)
			{
				merged->right = new TreeNode();
				merge(nullptr, root2->right, merged->right);
			}

			return;
		}

		if (root2 == nullptr)
		{
			// root2 has val
			merged->val = root1->val;
			if (root1->left != nullptr)
			{
				merged->left = new TreeNode();
				merge(root1->left, nullptr, merged->left);
			}

			if (root1->right != nullptr)
			{
				merged->right = new TreeNode();
				merge(root1->right, nullptr, merged->right);
			}

			return;
		}
	}
};

void print(TreeNode *n)
{
	if (n == nullptr)
	{
		// std::cout << "^";
		return;
	}

	std::cout << n->val << ", ";
	print(n->left);
	print(n->right);
}

int main()
{
	TreeNode *root1 = new TreeNode(1);
	root1->left = new TreeNode(3);
	root1->right = new TreeNode(2);
	root1->left->left = new TreeNode(5);

	TreeNode *root2 = new TreeNode(2);
	root2->left = new TreeNode(1);
	root2->right = new TreeNode(3);
	root2->left->right = new TreeNode(4);
	root2->right->right = new TreeNode(7);

	print(root1);
	std::cout << "\n";

	print(root2);
	std::cout << "\n";

	std::cout << "Merge trees"
						<< "\n";
	Solution s;
	const auto merged = s.mergeTrees(root1, root2);
	print(merged);
	std::cout << "\n";
	std::cout << "\n";

	return 0;
}