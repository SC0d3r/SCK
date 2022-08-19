#include <iostream>
#include <vector>
#include <string>

class Solution
{
public:
	inline std::string mergeAlternately(std::string &word1, std::string &word2)
	{
		const auto len1 = word1.size();
		const auto len2 = word2.size();
		int p = 0;
		int q = 0;

		std::string res = "";
		while (p < len1 && q < len2)
		{
			res += word1.substr(p++, 1) + word2.substr(q++, 1);
		}

		if (p < len1)
			res += word1.substr(p);
		if (q < len2)
			res += word2.substr(q);

		return res;
	}
};

int main()
{
	std::string a = "abc";
	std::string b = "xyzww";
	Solution s;
	std::cout << "ans: " << s.mergeAlternately(a, b) << std::endl;
	return 0;
}