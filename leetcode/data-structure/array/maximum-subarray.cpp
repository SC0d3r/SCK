#include <iostream>
#include <vector>
#include <set>

class Solution
{
public:
	int maxSubArray(std::vector<int> &nums)
	{
		const auto len = nums.size();
		if (len == 1)
			return nums[0];

		// first approach:
		// runtime: time limit exceeded!
		// int maximum = -9999999999;

		// // first approach using moving window
		// // std::set<int> sums;
		// int length = len;
		// std::vector<int> startRange;

		// int i = 0;
		// while (length > 0)
		// {
		// 	startRange = getStartRange(len - length);
		// 	const auto sLen = startRange.size();
		// 	for (const auto s : startRange)
		// 	{
		// 		const auto result = calcSum(s, len + s - (sLen - 1), nums);
		// 		if (result > maximum)
		// 			maximum = result;
		// 	}
		// 	length--;
		// }

		// return maximum;

		// second approach : brute force
		int cSum = 0, mSum = -99999999;
		int i = 0;
		for (i = 0; i < len; i++)
		{
			const auto x = nums[i];
			cSum += x;
			if (x > cSum)
			{
				cSum = x;
			}

			if (cSum > mSum)
				mSum = cSum;
		}

		return mSum;
	}

private:
	inline std::vector<int> getStartRange(int n)
	{
		std::vector<int> res;
		for (int i = 0; i <= n; i++)
		{
			res.push_back(i);
		}
		return res;
	}

	inline int calcSum(int startIndex, int length, std::vector<int> &arr)
	{
		int res = 0;
		const auto len = arr.size();
		int i;
		for (i = startIndex; i < length; i++)
		{
			res += arr[i];
		}

		return res;
	}
};

int main()
{
	std::vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	Solution s;
	std::cout << "Max sum: " << s.maxSubArray(nums) << std::endl;
	return 0;
}