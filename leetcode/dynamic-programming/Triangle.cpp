#include <iostream>
#include <vector>

class Solution
{
public:
	int minimumTotal(std::vector<std::vector<int>> &triangle)
	{
		std::vector<std::vector<int>> memo(triangle.size(), std::vector<int>(triangle.back().size(), -1));
		return recur(triangle, triangle[0], 0, 0, triangle.size(), memo);
	}

	int recur(std::vector<std::vector<int>> &triangle, std::vector<int> &xs, int i, int pickedIdx, const int &len, std::vector<std::vector<int>> &memo)
	{
		// it reached the end
		if (i == len)
			return 0;

		// if this illegal index so just punish it by returning
		// a big number
		if (pickedIdx >= xs.size())
			return 1e3;

		const auto memoizedVal = memo[i][pickedIdx];
		if (memoizedVal != -1)
			return memoizedVal;

		const auto path1 = triangle[i][pickedIdx] + recur(triangle, triangle[i + 1], i + 1, pickedIdx, len, memo);
		const auto path2 = triangle[i][pickedIdx] + recur(triangle, triangle[i + 1], i + 1, pickedIdx + 1, len, memo);
		return memo[i][pickedIdx] = std::min(path1, path2);
	}
};

int main()
{
	Solution s;
	std::vector<std::vector<int>> nums = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
	std::cout << "min: " << s.minimumTotal(nums) << std::endl;
	return 0;
}

// 	int greedy(std::vector<std::vector<int>> &triangle)
// 	{
// 		// method 1: greedy (naive approach)
// 		// this shouldnt find the optimal path
// 		// this doesnt work and the example is [[-1],[2,3],[1,-1,-3]]

// 		int min = triangle[0][0];
// 		const auto len = triangle.size();

// 		auto picked = 0;
// 		for (int i = 1; i < len; i++)
// 		{
// 			const auto xs = triangle[i];
// 			const auto l = xs.size();
// 			const auto choice1 = xs[picked];
// 			int choice2 = 1e3;
// 			if (picked + 1 < l)
// 			{
// 				choice2 = xs[picked + 1];
// 			}
// 			const auto x = std::min(choice1, choice2);
// 			if (x == choice2)
// 				picked++;
// 			min += x;
// 		}

// 		return min;
// 	}