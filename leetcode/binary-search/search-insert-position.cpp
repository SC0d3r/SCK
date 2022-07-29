#include <iostream>
#include <vector>

class Solution
{
public:
	int searchInsert(std::vector<int> &nums, int target)
	{
		int min = 0;
		int max = nums.size();
		while (true)
		{
			int pv = (min + max) / 2;
			const auto x = nums[pv];
			if (x == target)
				return pv;
			if ((max - min) == 1)
			{
				if (target > nums[min])
					return max;
				else
					return min;
			}

			if (x < target)
			{
				min = pv;
			}
			else
			{
				max = pv;
			}
		}
	}
};

int main()
{
	std::vector<int> l = {1, 3, 5, 6};
	Solution s;
	std::cout << "index: " << s.searchInsert(l, 2) << std::endl;
	return 0;
}