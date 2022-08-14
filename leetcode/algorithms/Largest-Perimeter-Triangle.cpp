#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
	inline int largestPerimeter(std::vector<int> &nums)
	{
		const auto len = nums.size();
		// method 1: sorting and recursion
		// runtime: 29ms
		std::sort(nums.begin(), nums.end());
		return solve(nums, len);
	}

private:
	inline int solve(std::vector<int> &nums, const int &idx)
	{
		if (idx == 2)
			return 0;
		const auto a = nums[idx - 1];
		const auto b = nums[idx - 2];
		const auto c = nums[idx - 3];

		if ((b + c) > a)
			return a + b + c;
		return solve(nums, idx - 1);
	}
};

int main()
{
	Solution s;
	std::vector<int> tr = {3, 2, 3, 4};
	std::cout << "ans: " << s.largestPerimeter(tr) << std::endl;
	return 0;
}