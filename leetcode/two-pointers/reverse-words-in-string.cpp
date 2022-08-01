#include <iostream>
#include <vector>
#include <string>

class Solution
{
public:
	std::string &reverseWords(std::string &s)
	{
		const auto len = s.size();
		int i = 0;
		int lp = 0;
		for (i = 0; i < len; i++)
		{
			const auto x = s[i];
			if (x == ' ')
			{
				reverse(s, lp, i - 1);
				lp = i + 1;
			}
		}

		// reverse the last word
		reverse(s, lp, len - 1);

		return s;
	}

private:
	inline void reverse(std::string &s, int lp, int rp)
	{
		while (lp < rp)
		{
			const auto temp = s[lp];
			s[lp++] = s[rp];
			s[rp--] = temp;
		}
	}
};

int main()
{
	// std::vector<char> chars = {'h', 'e', 'l', 'l', 'o'};
	std::string str = "Hello To World";
	Solution s;
	const auto res = s.reverseWords(str);
	std::cout << "resuult is: " << res << "\n";

	return 0;
}