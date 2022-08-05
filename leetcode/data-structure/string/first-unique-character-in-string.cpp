#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

class Solution
{
public:
	inline int firstUniqChar(std::string s)
	{
		const auto len = s.size();

		// method 1: using hashmap
		// runtime: 91ms

		// int i = 0;
		// std::unordered_map<char, int> m;
		// for (i = 0; i < len; i++)
		// {
		// 	if (m[s[i]] != 0)
		// 		m[s[i]] = -1;
		// 	else
		// 		m[s[i]] = i + 1;
		// }

		// for (i = 0; i < len; i++)
		// {
		// 	if (m[s[i]] != -1)
		// 		return m[s[i]] - 1;
		// }

		// method 2: using built in string::find, string::substr
		// runtime: ??ms
		// memory: Memory Limit Exceeded!

		// int i = 0;
		// for (i = 0; i < len; i++)
		// {

		// 	if ((s.substr(i + 1).find(s[i]) == std::string::npos) && (s.substr(0, i).find(s[i]) == std::string::npos))
		// 		return i;
		// }

		// method 3: second time loop the map and not the string
		// runtime: 28ms at the best run

		int i = 0;
		typedef std::pair<int, int> pair; // pair(count, index)
		std::vector<pair> chars(256, std::make_pair(0, 0));
		for (i = 0; i < len; i++)
		{
			(chars[s[i]].first)++;
			chars[s[i]].second = i;
		}

		int res = 1e6;
		for (const auto p : chars)
		{
			if (p.first == 1)
			{
				res = std::min(res, p.second);
			}
		}

		return res == 1e6 ? -1 : res;
	}
};

int main()
{
	std::string s = "loveleetcode";
	std::string s2 = "aabb";
	Solution so;
	std::cout << "result: " << so.firstUniqChar(s) << std::endl;
	return 0;
}