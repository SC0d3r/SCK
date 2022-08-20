#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

class Solution
{
public:
	inline bool isAlienSorted(std::vector<std::string> &words, std::string &order)
	{
		const auto len = words.size();
		createMapping(order);

		for (int i = 0; i < len - 1; i++)
		{
			auto &w1 = words[i];
			if (i == 0)
				mapWord(w1, order);
			auto &w2 = words[i + 1];
			mapWord(w2, order);
			if (w1 > w2)
				return false;
		}

		return true;
	}

private:
	std::unordered_map<char, char> m;
	std::string alpha = "abcdefghijklmnopqrstuvwxyz";
	inline void createMapping(std::string &order)
	{
		for (int i = 0; i < 26; i++)
			m[order[i]] = alpha[i];
	}

	inline void mapWord(std::string &word, std::string &alpha)
	{
		for (auto &c : word)
			c = m[c];
	}
};

int main()
{

	std::vector<std::string> words = {"word", "world", "row"};
	std::string order = "worldabcefghijkmnpqstuvxyz";
	//									"abcdefghijklmnopqrstuvwxyz"
	Solution s;
	std::cout << "ans: " << s.isAlienSorted(words, order) << std::endl;
	return 0;
}