#include <iostream>
#include <vector>
#include <string>

class Solution
{
public:
	std::vector<std::vector<int>> res;
	inline std::vector<std::vector<int>> &permute(std::vector<int> &nums)
	{
		std::vector<int> xs;
		const auto len = nums.size();
		recur(xs, nums, len);
		return res;
	}
	inline void recur(std::vector<int> &xs, std::vector<int> &nums, const int &len)
	{
		if (xs.size() == len)
		{
			res.emplace_back(xs);
			return;
		}

		for (auto it = nums.begin(); it != nums.end(); it++)
		{
			const auto x = *(it);
			xs.push_back(x);
			nums.erase(it);
			recur(xs, nums, len);
			nums.insert(it, x);
			xs.pop_back();
		}
	}
};

int main()
{
	Solution s;
	std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8};
	const auto res = s.permute(nums);

	for (const auto xs : res)
	{
		for (const auto x : xs)
		{
			std::cout << x << ", ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	return 0;
}