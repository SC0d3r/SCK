#include <iostream>
#include <vector>
#include <numeric>

const auto sum = [](int a, int b)
{ return a + b; };

class Solution
{
public:
	int maximumWealth(std::vector<std::vector<int>> &accounts)
	{
		int max = 0;
		const auto len = accounts.size();
		// method 1: using accum
		// runtime: 6ms

		for (int i = 0; i < len; i++)
		{
			const auto xs = accounts[i];
			const auto res = std::accumulate(xs.begin(), xs.end(), 0, sum);
			if (res > max)
				max = res;
		}

		// method 2: just using for loop
		// runtime: 4ms

		// for (int i = 0; i < len; i++)
		// {
		// 	const auto xs = accounts[i];
		// 	int sum = 0;
		// 	for (int j = 0; j < xs.size(); j++)
		// 	{
		// 		sum += xs[j];
		// 	}
		// 	if (sum > max)
		// 		max = sum;
		// }

		return max;
	}
};

int main()
{
	Solution s;
	std::vector<std::vector<int>> grid = {
			{1, 2, 3},
			{3, 1, 2},
	};
	std::cout << "ans: " << s.maximumWealth(grid) << std::endl;

	return 0;
}