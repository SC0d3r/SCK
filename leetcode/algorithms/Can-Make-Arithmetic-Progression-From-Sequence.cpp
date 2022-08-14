#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
	inline bool canMakeArithmeticProgression(std::vector<int> &arr)
	{
		const auto len = arr.size();

		std::sort(arr.begin(), arr.end());
		for (int i = 1; i < len - 1; i++)
		{
			const auto d1 = arr[i] - arr[i - 1];
			const auto d2 = arr[i + 1] - arr[i];
			if (d1 != d2)
				return false;
		}
		return true;
	}
};

int main()
{
	Solution s;
	std::vector<int> arr = {1, 2, 3};
	std::cout << "ans: " << s.canMakeArithmeticProgression(arr) << std::endl;
	return 0;
}
