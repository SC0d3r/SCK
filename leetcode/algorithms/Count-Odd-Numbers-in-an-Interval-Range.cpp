#include <iostream>
#include <vector>

class Solution
{
public:
	inline int countOdds(int low, int high)
	{
		// method 1: (home grown method)
		// runtime: 0ms
		const auto evensTillHigh = high / 2;
		const auto excludeEven = low == 0 ? -1 : (low - 1) / 2;
		const auto totalEvens = evensTillHigh - excludeEven;
		const auto countNumbers = high - low + 1;

		return countNumbers - totalEvens; // this is the total of odds

		// method 2:
		// return (high + 1) / 2 - low / 2;
	}
};

int main()
{
	Solution s;
	std::cout << "ans: " << s.countOdds(3, 7) << std::endl;
	return 0;
}