#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <utility>

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
	// using recursion works but its slow
	// so the key point is (3,4) and (4,3) have the same result
	// runtime: 0ms
	typedef std::pair<int, int> pair;
	inline int uniquePaths(int m, int n)
	{
		if (m == 0 || n == 0)
			return 0;
		if (m == 1)
			return 1;
		if (n == 1)
			return 1;
		if (n == 2)
		{
			return m;
		}
		if (m == 2)
		{
			return n;
		}
		const auto key = std::make_pair(m, n);
		// const auto key = std::to_string(m) + "," + std::to_string(n);
		const auto cache = cacheMap[key];
		if (cache != 0)
		{
			// found
			return cache;
		}

		// const auto key_reverse = std::to_string(n) + "," + std::to_string(m);
		const auto key_reverse = std::make_pair(n, m);
		const auto cache_rev = cacheMap[key_reverse];
		if (cache_rev != 0)
		{
			// found
			return cache_rev;
		}

		const auto res = uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
		cacheMap[key] = res;
		return res;
	}

	int uniquePaths2(int m, int n)
	{
		if (m == 0 || n == 0)
			return 0;
		if (m == 1)
			return 1;
		if (n == 1)
			return 1;

		int res = 0;
		std::vector<std::vector<int>> stack{{m, n}};
		while (stack.size() != 0)
		{
			// get the subproblem
			const auto sub = stack.back();
			stack.pop_back();

			const auto mm = sub[0];
			const auto nn = sub[1];
			// first sub problem
			auto key = std::make_pair(mm - 1, nn);
			// auto key = std::to_string(mm - 1) + "," + std::to_string(nn);
			auto cache = cacheMap[key];
			if (cache != 0)
			{
				// found
				res += cache;
			}
			else
			{
				if ((mm - 1) == 1 || nn == 1)
				{
					res += 1;
				}
				else
					stack.push_back({mm - 1, nn});
			}

			// second sub problem
			// key = std::to_string(mm) + "," + std::to_string(nn - 1);
			key = std::make_pair(mm, nn - 1);
			cache = cacheMap[key];
			if (cache != 0)
			{
				// found
				res += cache;
			}
			else
			{
				if (mm == 1 || (nn - 1) == 1)
				{
					res += 1;
				}
				else
					stack.push_back({mm, nn - 1});
			}
		}
		return res;
	}

private:
	std::unordered_map<pair, int, pair_hash> cacheMap;
	// std::unordered_map<std::string, int> cacheMap;
};

int main()
{
	Solution s;
	std::cout << s.uniquePaths(5, 5) << "\n";
	return 0;
}
