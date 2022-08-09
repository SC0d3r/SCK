#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
class Solution
{
public:
	typedef std::vector<std::vector<int>> twoD;
	twoD res;
	inline std::vector<std::vector<int>> combine(int n, int k)
	{

		// if (k > n)
		// 	return {};
		if (k == 0 || n == k)
		{
			std::vector<int> vec;
			int i = 1;
			while (i <= n)
			{
				vec.emplace_back(i++);
			}
			res.emplace_back(vec);
			return res;
		}

		// method 2:
		// runtime: 29ms faster than 80% of submissions (is it fast enough?)

		// std::vector<std::vector<int>> res;
		std::vector<int> choices;
		int i;
		for (i = 1; i <= n; i++)
			choices.emplace_back(i);

		for (i = 0; i < n - k + 1; i++)
			recur({}, i, choices, res, n, k);

		return res;
	}

private:
	inline void recur(std::vector<int> xs, int idx, std::vector<int> &choices, std::vector<std::vector<int>> &res, int &n, int &k)
	{
		// int remainings = n - idx;
		if ((n - idx + xs.size()) < k)
			return;
		xs.emplace_back(choices[idx]);
		idx++;

		if (xs.size() == k)
		{
			// found answer
			res.emplace_back(xs);
			return;
		}

		for (int i = idx; i < n; i++)
		{
			recur(xs, i, choices, res, n, k);
		}
	}
};

int main()
{
	Solution s;

	const auto res = s.combine(20, 16);
	for (const auto xs : res)
	{
		for (const auto x : xs)
		{
			std::cout << x << ", ";
		}
		std::cout << std::endl;
	}
	return 0;
}