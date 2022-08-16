#include <iostream>
#include <vector>
#include <string>

class Solution
{
public:
	inline int firstUniqChar(std::string s)
	{
		std::pair<int, int> arr[256];
		const auto len = s.size();
		for (int i = 0; i < len; i++)
		{
			arr[s[i]].first++;
			if (!arr[s[i]].second)
				arr[s[i]].second = i;
		}

		int idx = 1e3;
		for (int i = 0; i < 256; i++)
		{
			if (arr[i].first == 1)
				idx = std::min(arr[i].second, idx);
		}

		return idx;
	}
};

int main()
{
	Solution so;
	std::string s = "leetcode";
	std::cout << "ans: " << so.firstUniqChar(s) << std::endl;
	return 0;
}