#include <iostream>
#include <vector>

class Solution
{
public:
	int search(std::vector<int> &nums, int target)
	{
		auto len = nums.size();
		int max = len;
		int min = 0;
		int pivot = (max + min) / 2;
		while (true)
		{
			const auto x = nums[pivot];

			if (x == target)
				return pivot;

			if (pivot == min || pivot == max)
			{
				return -1;
			}

			if (x > target)
			{
				max = pivot;
				pivot = (min + max) / 2;
			}
			else
			{
				min = pivot;
				pivot = (min + max) / 2;
			}
		}
	}
};

// int main()
// {
// 	std::vector<int> a = {-1, 0, 3, 5, 9, 12};
// 	Solution s;
// 	std::cout << "index is " << s.search(a, 2);
// 	return 0;
// }