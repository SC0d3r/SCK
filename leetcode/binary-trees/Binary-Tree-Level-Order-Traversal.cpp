#include <iostream>
#include <vector>
#include <queue>

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
	std::vector<std::vector<int>> res;
	inline std::vector<std::vector<int>> &levelOrder(TreeNode *root)
	{
		if (!root)
			return res;

		// method 1: using dfs recursion
		// runtime: 4ms at best run

		recur(res, root, 0);

		// method 2: using bfs with queues
		// runtime: 4ms at best run

		// std::queue<std::vector<TreeNode *>> q;
		// q.push({root});
		// std::vector<int> xs;
		// std::vector<TreeNode *> newBatch;
		// while (!q.empty())
		// {
		// 	newBatch.clear();
		// 	xs.clear();
		// 	const auto batch = q.front();
		// 	q.pop();
		// 	for (const auto b : batch)
		// 	{
		// 		xs.push_back(b->val);
		// 		if (b->left)
		// 			newBatch.push_back(b->left);
		// 		if (b->right)
		// 			newBatch.push_back(b->right);
		// 	}
		// 	res.push_back(xs);
		// 	if (newBatch.size())
		// 		q.push(newBatch);
		// }

		return res;
	}

	inline void recur(std::vector<std::vector<int>> &res, TreeNode *node, int level)
	{
		if (!node)
			return;
		if (res.size() < (level + 1))
		{
			res.push_back({});
		}

		res[level].push_back(node->val);
		recur(res, node->left, level + 1);
		recur(res, node->right, level + 1);
	}
};

int main()
{
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	Solution s;
	const auto res = s.levelOrder(root);

	for (const auto xs : res)
	{
		if (xs.size() == 0)
			std::cout << "=========== ";
		for (const auto x : xs)
		{
			std::cout << x << ", ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;
	return 0;
}