#include <iostream>
#include <vector>

class Solution
{
public:
	void reverseString(std::vector<char> &s)
	{
		const auto len = s.size();
		int lp = 0;
		int rp = len - 1;

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
	std::vector<char> chars = {'h', 'e', 'l', 'l', 'o'};
	Solution s;
	s.reverseString(chars);
	for (const auto c : chars)
	{
		std::cout << c << std::endl;
	}

	return 0;
}