#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

class Solution
{
public:
	inline std::string freqAlphabets(std::string &s)
	{
		const auto len = s.size();
		std::string res;
		while (p < len)
		{
			const auto t = consume(s, len);
			const auto intT = std::stoi(t);
			res += alpha[intT - 1];
		}
		return res;
	}

private:
	std::string alpha = "abcdefghijklmnopqrstuvwxyz";
	int p = 0;
	std::string consume(std::string &s, const int len)
	{
		if ((p + 2) < len && s[p + 2] == '#')
		{
			const auto res = s.substr(p, 2);
			p += 3;
			return res;
		}
		const auto res = s.substr(p, 1);
		p++;
		return res;
	}
};

int main()
{
	std::string s = "21#523#12#22#611#71910#721#18#8";
	Solution so;
	std::cout << "ans: " << so.freqAlphabets(s) << std::endl;
	return 0;
}