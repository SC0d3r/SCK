#include <iostream>
#include <vector>

class Solution
{
public:
	inline void moveZeroes(std::vector<int> &nums)
	{
		const size_t len = nums.size();

		// naive approach:
		// first we find all the indexex of zero elemetns
		// then we remove them and add that much zero to the end of vector
		// runtime: 164ms

		// std::vector<int> zeros;
		// for (int i = 0; i < len; i++)
		// {
		// 	if (nums[i] == 0)
		// 		zeros.push_back(i);
		// }

		// const auto zLen = zeros.size();
		// for (int i = 0; i < zLen; i++)
		// {
		// 	nums.erase(nums.begin() + zeros[i] - i);
		// }

		// for (int i = 0; i < zLen; i++)
		// {
		// 	nums.push_back(0);
		// }

		// second approach:
		// we this on only one pointer
		// runtime: 497ms

		// int lp = 0;
		// int rp = 1;
		// if (len <= 1)
		// 	return;

		// while (lp < len - 1)
		// {
		// 	const auto x = nums[lp];
		// 	auto y = nums[rp];
		// 	if (x != 0)
		// 	{
		// 		lp++;
		// 		rp = lp + 1;
		// 		continue;
		// 	}
		// 	// x here is 0
		// 	// so we find the first non zero element to replace with x
		// 	while (y == 0 && rp < len)
		// 	{
		// 		rp++;
		// 		if (rp < len)
		// 			y = nums[rp];
		// 	}
		// 	if (rp == len)
		// 		return;

		// 	// we found one
		// 	nums[lp] = y;
		// 	nums[rp] = 0;
		// 	lp++;
		// 	rp = lp + 1;
		// }

		// thrid approach:
		// two pointers zeros & non-zeros
		// runtime: 386ms

		// int zp = 0;
		// for (int i = 0; i < len; i++)
		// {
		// 	while (zp < len && nums[zp] != 0)
		// 	{
		// 		// find the first zero element
		// 		zp++;
		// 	}
		// 	if (zp == len)
		// 		return;
		// 	int xp = zp + 1;
		// 	while (xp < len && nums[xp] == 0)
		// 	{
		// 		// find the first non zero after zp
		// 		xp++;
		// 	}
		// 	if (xp == len)
		// 		return;

		// 	// swap  zp , xp
		// 	nums[zp] = nums[xp];
		// 	nums[xp] = 0;
		// 	zp++;
		// }

		// fourth approach:
		int zp = 0;
		for (int i = 0; i < len; i++)
		{
			if (nums[i] != 0 && nums[zp] == 0)
			{
				// swap
				nums[zp] = nums[i];
				nums[i] = 0;
			}
			if (nums[zp] != 0)
				zp++;
		}
	}
};

int main()
{
	Solution s;
	std::vector<int> nums = {0, 1, 2, 0, 3};
	s.moveZeroes(nums);
	for (auto x : nums)
	{
		std::cout << x << "\n";
	}
	return 0;
}