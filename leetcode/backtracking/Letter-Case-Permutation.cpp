#include <iostream>
#include <vector>
#include <string>

class Solution
{
public:
	std::vector<std::string> res;
	inline std::vector<std::string> &letterCasePermutation(std::string &s)
	{
		const auto len = s.size();
		for (auto &c : s)
		{
			c = std::tolower(c);
		}

		recur(s, 0, len);
		return res;
	}

	inline void recur(std::string &str, int idx, const int &len)
	{
		if (idx == len)
		{
			res.emplace_back(str);
			return;
		}

		if (std::isdigit(str[idx]))
		{
			recur(str, idx + 1, len);
			return;
		}

		recur(str, idx + 1, len);
		str[idx] = std::toupper(str[idx]);
		recur(str, idx + 1, len);
		str[idx] = std::tolower(str[idx]);
	}
};

int main()
{
	std::string s = "a1b2c23sdbdf3423sad234sf";
	Solution so;
	const auto res = so.letterCasePermutation(s);
	for (const auto xs : res)
	{
		for (const auto x : xs)
		{
			std::cout << x << ", ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	return 0;
}