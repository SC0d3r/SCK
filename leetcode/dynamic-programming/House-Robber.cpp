#include <iostream>
#include <vector>
#include <unordered_map>

class Solution
{
public:
	inline int rob(std::vector<int> &nums)
	{
		const auto len = nums.size();
		std::vector<int> memo(len, -1);
		return max(nums, len - 1, memo);
	}

	inline int max(std::vector<int> &nums, int n, std::vector<int> &memo)
	{
		if (n < 0)
			return 0;
		if (n == 0)
			return nums[0];
		if (memo[n] != -1)
			return memo[n];

		int picked = nums[n] + max(nums, n - 2, memo);
		int notPicked = max(nums, n - 1, memo);
		return memo[n] = std::max(picked, notPicked);
	}
};

int main()
{
	Solution s;
	std::vector<int> nums = {2, 7, 9, 3, 1};
	std::cout << "max: " << s.rob(nums) << std::endl;
	return 0;
}