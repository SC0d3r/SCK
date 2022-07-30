#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
	void rotate(std::vector<int> &nums, int k)
	{
		const size_t len = nums.size();
		const int rotation = k % len;
		if (rotation == 0)
		{
			// this means a full rotation then do nothing
			return;
		}

		// 1- we turn the vector in to K and len - K part
		// 2- reserve those in palce
		// 3- reverse the whole vector
		long lp = 0;
		long rp = len - rotation - 1;
		reverseInPlace(nums, lp, rp);

		lp = len - rotation;
		rp = len - 1;
		reverseInPlace(nums, lp, rp);

		// std::reverse(nums.begin(), nums.end());
		reverseInPlace(nums, 0, len - 1);

		// first naive appraoch
		// for (int i = 0; i < k; i++)
		// {
		// 	const int x = nums[len - 1];
		// 	nums.pop_back();
		// 	nums.insert(nums.begin(), x);
		// }
	}

private:
	// adding this inline made the runtime from 49ms -> 34ms
	inline void reverseInPlace(std::vector<int> &vec, long lp, long rp)
	{
		while (lp < rp)
		{
			// swap in place
			long temp = vec[lp];
			vec[lp] = vec[rp];
			vec[rp] = temp;
			lp++;
			rp--;
		}
	}
};

int main()
{
	Solution s;
	std::vector<int> nums = {0, 1, 2, 3, 4, 5, 6, 6};
	int k = 23;
	s.rotate(nums, k);
	for (auto x : nums)
		std::cout << x << "\n";
	return 0;
}