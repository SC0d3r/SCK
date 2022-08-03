#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

class Solution
{
public:
	inline int lengthOfLongestSubstring(std::string s)
	{
		const auto len = s.size();
		int max = 0;

		// method 1: works but too slow
		// runtime: 1544ms yikes!

		// int p1 = 0;
		// int i = 0;
		// while (p1 < len)
		// {
		// 	std::unordered_map<char, int> m;
		// 	for (i = p1; i < len; i++)
		// 	{
		// 		const auto x = s[i];
		// 		const auto found = m[x];
		// 		if (found != 0)
		// 			break;
		// 		m[x]++;
		// 	}
		// 	const auto l = i - p1;
		// 	if (l > max)
		// 		max = l;

		// 	p1++;
		// }

		// method 2: O(N ^ 2) using visited vector instead of map
		// runtime: 49ms

		// int i = 0;
		// int j = 0;
		// for (i = 0; i < len; i++)
		// {
		// 	std::vector<bool> visited(256);

		// 	for (j = i; j < len; j++)
		// 	{
		// 		// const auto x = s[j];
		// 		if (visited[s[j]])
		// 		{
		// 			break;
		// 		}
		// 		else
		// 		{
		// 			const auto l = j - i + 1;
		// 			if (l > max)
		// 				max = l;
		// 			visited[s[j]] = true;
		// 		}
		// 	}
		// }

		// method 3: O(N) sliding window
		// runtime: 4ms

		int i = 0;
		int j = 0;
		std::vector<int> lastIndex(256, -1); // default value is -1
		for (j = 0; j < len; j++)
		{
			const auto x = s[j];
			i = std::max(i, lastIndex[x] + 1);
			max = std::max(max, j - i + 1);
			lastIndex[x] = j;
		}

		return max;
	}
};

int main()
{
	Solution s;
	std::string str = "dvdf";
	std::cout << "ans: " << s.lengthOfLongestSubstring(str) << std::endl;
	return 0;
}