#include <iostream>
#include <vector>
#include <unordered_map>

struct pair_hash
{
	template <class T1, class T2>
	std::size_t operator()(const std::pair<T1, T2> &pair) const
	{
		return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
	}
};

class Solution
{
public:
	typedef std::pair<int, int> pair;
	inline std::vector<std::vector<int>> generate(int numRows)
	{
		// method 1: using DP
		// runtime: 0ms

		std::vector<std::vector<int>> res;
		int i = 0;
		int j = 0;
		for (i = 0; i < numRows; i++)
		{
			std::vector<int> row;
			for (j = 0; j <= i; j++)
			{
				row.emplace_back(getNum(i, j));
			}
			res.emplace_back(row);
		}
		return res;
	}

private:
	inline int getNum(int i, int j)
	{
		if (i == j)
			return 1;
		if (j == 0)
			return 1;

		const auto key = std::make_pair(i, j);
		const auto x = m[key];

		if (x != 0)
			// found
			return x;

		const auto res = getNum(i - 1, j) + getNum(i - 1, j - 1);
		m[key] = res;
		return res;
	}

	std::unordered_map<pair, int, pair_hash> m;
};

int main()
{
	Solution s;
	const auto res = s.generate(4);

	for (const auto xs : res)
	{
		for (int i = 0; i < xs.size(); i++)
		{
			std::string s = "";
			if (i != xs.size() - 1)
			{
				s = ", ";
			}
			std::cout << xs[i] << s;
		}
		std::cout << "\n";
	}

	return 0;
}
