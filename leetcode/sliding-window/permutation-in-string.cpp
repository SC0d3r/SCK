#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

class Solution
{
public:
	inline bool checkInclusion(std::string s1, std::string s2)
	{
		const auto s1Len = s1.size();
		const auto s2Len = s2.size();

		// method 1: using hashmap and sliding window
		// runtime: 2479ms -- too slow

		// creating a map from s1
		for (const auto c : s1)
		{
			m[c]++;
		}

		int p1 = 0;
		int p2 = s1Len;

		int i = 0;
		while (p2 < s2Len + 1)
		{
			// lets map the window string as well and check the frequencies
			std::unordered_map<char, int> mWin;
			for (i = p1; i < p2; i++)
			{
				mWin[s2[i]]++;
			}

			bool didMatch = true;
			for (const auto &[key, val] : mWin)
			{
				if (m[key] != val)
				{
					didMatch = false;
					break;
				}
			}
			if (didMatch)
				return true;

			p1++;
			p2++;
		}

		return false;
	}

private:
	std::unordered_map<char, int> m;
};

int main()
{
	Solution s;
	std::string s1 = "ab";
	std::string s2 = "eidaboooo";
	std::cout << "res is: " << s.checkInclusion(s1, s2) << std::endl;
	return 0;
}