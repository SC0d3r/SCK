#include <iostream>
#include <vector>
#include <string>
#include <set>

class Solution
{
public:
	const std::vector<std::string> morse = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
	inline int uniqueMorseRepresentations(std::vector<std::string> &words)
	{
		std::set<std::string> s;
		for (const auto w : words)
		{
			std::string res = "";
			for (const auto c : w)
				res += morse[c - 'a'];
			s.insert(res);
		}

		return s.size();
	}
};

int main()
{
	Solution s;
	std::vector<std::string> words = {"gin", "zen", "gig", "msg"};
	std::cout << "ans: " << s.uniqueMorseRepresentations(words) << std::endl;
	return 0;
}
