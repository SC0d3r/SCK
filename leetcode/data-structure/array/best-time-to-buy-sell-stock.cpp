#include <iostream>
#include <vector>

class Solution
{
public:
	inline int maxProfit(std::vector<int> &prices)
	{
		const auto len = prices.size();
		int max = -9999999;

		// method 1: brute force
		// runtime: time limit exceeded!
		// this is slow but works

		// int p1 = 0;
		// int p2 = 1;

		// while (p1 < len && p2 < len)
		// {
		// 	const auto x = prices[p1];
		// 	const auto y = prices[p2];
		// 	if (x > y)
		// 	{
		// 		p1 = p2;
		// 		p2 = p1 + 1;
		// 		continue;
		// 	}
		// 	p2++;
		// 	const auto profit = y - x;
		// 	if (profit > max)
		// 		max = profit;

		// 	if (p2 == len)
		// 	{
		// 		p1++;
		// 		p2 = p1 + 1;
		// 	}
		// }

		// method 2:
		// using buy value : O(N)
		// runtime: ??ms

		int i = 0;
		int buyValue = prices[0];
		for (i = 1; i < len; i++)
		{
			const auto x = prices[i];
			if (x < buyValue)
				buyValue = x;
			else
			{
				const auto p = x - buyValue;
				if (p > max)
					max = p;
			}
		}

		return max > 0 ? max : 0;
	}
};

int main()
{
	std::vector<int> prices = {7, 1, 5, 3, 6, 4};
	Solution s;
	std::cout << "max profit: " << s.maxProfit(prices) << std::endl;
	return 0;
}