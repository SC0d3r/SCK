#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

class Solution
{
public:
	// std::unordered_map<std::string, int> m = {
	// 		{"I", 1},
	// 		{"IV", 4},
	// 		{"V", 5},
	// 		{"IX", 9},
	// 		{"X", 10},
	// 		{"XL", 40},
	// 		{"L", 50},
	// 		{"XC", 90},
	// 		{"C", 100},
	// 		{"CD", 400},
	// 		{"D", 500},
	// 		{"CM", 900},
	// 		{"M", 1000},
	// };

	// for method 2:
	std::unordered_map<char, int> m2 = {
			{'I', 1},
			{'V', 5},
			{'X', 10},
			{'L', 50},
			{'C', 100},
			{'D', 500},
			{'M', 1000},
	};

	inline int romanToInt(std::string &s)
	{
		int res = 0;
		const auto len = s.size();

		// method 1:
		// runtime: 40ms not that fast

		// if (len == 1)
		// 	return m[s];
		// for (int i = 0; i < len; i++)
		// {
		// 	const auto x = m[s.substr(i, 2)];
		// 	if (x)
		// 	{
		// 		res += x;
		// 		i++;
		// 		continue;
		// 	}
		// 	res += m[s.substr(i, 1)];
		// }

		// method 2:
		// runtime: ??ms
		int i = 0;
		for (i = 0; i < len - 1; i++)
		{
			if (m2[s[i]] < m2[s[i + 1]])
			{
				res -= m2[s[i]];
			}
			else
				res += m2[s[i]];
		}
		res += m2[s[i]];

		return res;
	}
};

int main()
{
	std::string roman = "MCMXCIV";
	Solution s;
	std::cout << "ans: " << s.romanToInt(roman) << std::endl;
	return 0;
}
