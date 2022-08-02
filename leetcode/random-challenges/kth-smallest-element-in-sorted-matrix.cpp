#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
	inline int kthSmallest(std::vector<std::vector<int>> &matrix, int k)
	{
		const auto len = matrix.size();

		// method 1: brute force O(N ^ 2)
		// runtime: 37ms at the best run which is better than the 87%
		// of the submissions

		std::vector<int> ys;
		for (const auto xs : matrix)
		{
			for (const auto x : xs)
				ys.emplace_back(x);
		}

		std::sort(ys.begin(), ys.end());
		return ys[k - 1];
	}
};

int main()
{
	std::vector<std::vector<int>> m = {{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
	std::vector<std::vector<int>> m2 = {{1, 4, 7, 11, 15},
																			{2, 5, 8, 12, 19},
																			{3, 6, 9, 16, 22},
																			{10, 13, 14, 17, 24},
																			{18, 21, 23, 26, 30}};

	Solution s;
	std::cout << "result: " << s.kthSmallest(m2, 20) << std::endl;
	return 0;
}