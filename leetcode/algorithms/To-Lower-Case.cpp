#include <iostream>
#include <vector>
#include <string>

class Solution
{
public:
	inline std::string &toLowerCase(std::string &s)
	{
		for (auto &c : s)
			c = std::tolower(c);
		return s;
	}
};

int main()
{
	std::string s = "ABC";
	Solution so;
	std::cout << "ans: " << so.toLowerCase(s) << std::endl;
	return 0;
}
