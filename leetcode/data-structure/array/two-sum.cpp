#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution
{
public:
	std::vector<int> twoSum(std::vector<int> &nums, int target)
	{
		const auto len = nums.size();
		// first approach: using hashmap
		// runtime: 21ms at best run

		std::unordered_map<int, int> m;
		int i = 0;
		for (i = 0; i < len; i++)
		{
			m[nums[i]] = i + 1; // we want to use 0 to check if index is present or not
		}

		for (i = 0; i < len; i++)
		{
			const auto x = nums[i];
			const auto diff = target - x;
			const auto maybeFoundIndex = m[diff];
			if (maybeFoundIndex != 0 && (maybeFoundIndex - 1) != i)
			{
				return {maybeFoundIndex - 1, i};
			}
		}

		// second approach: sorting then using two-pointers
		// we cannot use this approach cause we need either arrays be sorted from the begining
		// or just return the numbers that add up to the target otherwise sorting will mess up the
		// indices

		// std::sort(nums.begin(), nums.end());
		// int lp = 0;
		// int rp = len - 1;
		// while (lp < rp)
		// {
		// 	const auto maybeTarget = nums[lp] + nums[rp];
		// 	if (maybeTarget == target)
		// 	{
		// 		return {lp, rp};
		// 	}
		// 	if (maybeTarget > target)
		// 	{
		// 		rp--;
		// 	}
		// 	else
		// 	{
		// 		lp++;
		// 	}
		// }

		return {0, 0};
	}
};

int main()
{
	std::vector<int> nums = {3, 2, 4};
	Solution s;
	const auto res = s.twoSum(nums, 6);
	for (const auto x : res)
	{
		std::cout << x << "\n";
	}

	return 0;
}