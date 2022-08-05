#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Solution
{
public:
	bool isAnagram(std::string s, std::string t)
	{
		if (s.size() != t.size())
			return false;
		// method 1:
		// runtime: 14ms at best run: faster than 57% but seems a bit slow
		// std::sort(s.begin(), s.end());
		// std::sort(t.begin(), t.end());

		// for (int i = 0; i < s.size(); i++)
		// {
		// 	if (s[i] != t[i])
		// 		return false;
		// }

		// return true;

		// method 2: using vector and counting
		// runtime: 7ms faster than 87% good enough

		std::vector<int> chars(256);
		for (const auto c : s)
		{
			chars[c]++;
		}

		for (const auto c : t)
		{
			chars[c]--;
			if (chars[c] < 0)
				return false;
		}

		return true;
	}
};

int main()
{
	std::string s = "anagram";
	std::string t = "nagaram";

	Solution so;
	std::cout << "Is it? " << (so.isAnagram(s, t) ? "True" : "False") << std::endl;
	return 0;
}