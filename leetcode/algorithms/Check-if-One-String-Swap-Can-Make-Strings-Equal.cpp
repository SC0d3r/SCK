#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

class Solution
{
public:
	inline bool areAlmostEqual(std::string s1, std::string s2)
	{
		if (s1 == s2)
			return true;
		const auto len = s1.size();
		int i = 0;
		std::vector<int> diffs;

		for (i = 0; i < len; i++)
		{
			if (s1[i] != s2[i])
			{
				diffs.emplace_back(i);
				if (diffs.size() > 2)
					return false;
			}
		}

		if (diffs.size() < 2)
			return false;

		const auto t = s2[diffs[0]];
		s2[diffs[0]] = s2[diffs[1]];
		s2[diffs[1]] = t;
		return s1 == s2;
	}
};

int main()
{
	Solution s;
	std::cout << "ans: " << s.areAlmostEqual("abc", "acb") << std::endl;
	return 0;
}