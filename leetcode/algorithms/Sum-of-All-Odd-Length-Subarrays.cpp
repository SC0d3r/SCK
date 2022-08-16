#include <iostream>
#include <vector>
#include <cmath>

class Solution
{
public:
	inline int sumOddLengthSubarrays(std::vector<int> &arr)
	{
		int res = 0;
		const auto len = arr.size();

		// method 1: not very fast O(N ^ 3)
		// runtime: 7ms~12ms

		// int howManyOdds = calcOdds(len);
		// for (int k = 0; k < howManyOdds; k++)
		// {
		// 	int odd = 1 + 2 * k;
		// 	int p = 0;
		// 	while ((p + odd) <= len)
		// 	{
		// 		const auto end = p + odd;
		// 		for (int i = p; i < end; i++)
		// 		{
		// 			res += arr[i];
		// 		}
		// 		p++;
		// 	}
		// }

		// method 2: fast O(N)
		// runtime: ??ms

		// this uses the fact the for each ith item in arr
		// there are (n - i) * (i + 1) / 2 choices (which appears in odd length sub arrays)
		// for example [1,  2,  3,  4,  5]
		// occurences:  3,  4,  5,  4,  3
		// example calculation: for 1 with index 0 we have: std::ceil((5 - 0) * (0 + 1) / 2) => 3;
		// then we can calc the result by doing => 1 * 3 + 2 * 4 + 3 * 5 + 4 * 4 + 5 * 3

		for (int i = 0; i < len; i++)
			res += arr[i] * std::ceil((len - i) * (i + 1) / 2.0);

		return res;
	}

private:
	int calcOdds(const int &n)
	{
		if (n % 2 == 0)
			return n / 2;
		return n / 2 + 1;
	}
};

int main()
{
	// std::vector<int> arr = {1};
	std::vector<int> arr = {1, 4, 2, 5, 3};
	Solution s;
	std::cout << "ans: " << s.sumOddLengthSubarrays(arr) << std::endl;
	return 0;
}
