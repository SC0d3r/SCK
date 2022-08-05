#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

class Solution
{
public:
	inline bool canConstruct(std::string ransomNote, std::string magazine)
	{
		// method 1:
		// runtime: 26ms at best run, seems a bit slow but faster than 51% of submissions

		// std::unordered_map<char, int> rn;
		// for (const auto c : ransomNote)
		// {
		// 	rn[c]++;
		// }

		// std::unordered_map<char, int> mag;
		// for (const auto c : magazine)
		// {
		// 	mag[c]++;
		// }

		// for (const auto [key, val] : rn)
		// {
		// 	if (mag[key] < val)
		// 		return false;
		// }

		// return true;

		// method 2: using a vector of 256 words and couting the occurences
		// runtime: 8ms faster than the 97% of online submissions

		std::vector<int> chars(256);
		for (const auto c : magazine)
		{
			chars[c] += 1;
		}

		for (const auto c : ransomNote)
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
	Solution s;
	std::string mag = "ab";
	std::string rn = "aa";
	std::cout << "can be built? " << (s.canConstruct(rn, mag) ? "True" : "False") << std::endl;
	return 0;
}