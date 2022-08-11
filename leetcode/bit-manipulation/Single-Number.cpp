#include <iostream>
#include <bitset>
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution
{
public:
	inline int singleNumber(std::vector<int> &nums)
	{
		const auto len = nums.size();
		if (len == 1)
			return nums[0];

		// method 1: using sort then loop
		// runtime: 28ms faster than 57% of submissions

		// std::sort(nums.begin(), nums.end());
		// int i = 0;
		// while (i < len)
		// {
		// 	if (nums[i] != nums[i + 1])
		// 		return nums[i];
		// 	i += 2;
		// }

		// method 2: using hashing
		// this method should be O(N) but uses more space
		// runtime: 30ms which takes longer than the sort(O(nlogn)) lol?

		// for (int i = 0; i < len; i++)
		// {
		// 	m[nums[i]]++;
		// }

		// btw I used the range loop and that was so much slower than this loop
		// for (auto it = m.begin(); it != m.end(); it++)
		// {
		// 	const auto p = *(it);
		// 	if (p.second == 1)
		// 		return p.first;
		// }

		// method 3: using xor
		// runtime: 16ms at the best run faster than the 96% of submissions

		return unique(nums, len);

		return -999;
	}

private:
	std::unordered_map<int, int> m;
	int unique(std::vector<int> &nums, const int len)
	{
		for (int i = 0; i < len - 1; i++)
		{
			nums[i + 1] = nums[i] ^ nums[i + 1];
		}

		return nums[len - 1];
	}
};

int main()
{
	Solution s;
	std::vector<int> nums = {1, 2, 1, 4, 2};
	std::cout << "result: " << s.singleNumber(nums) << std::endl;
	return 0;
}
