#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution
{
public:
	inline int minSetSize(std::vector<int> &arr)
	{
		std::unordered_map<int, int> m;
		const auto len = arr.size();
		const auto half = len / 2;

		for (int i = 0; i < len; i++)
		{
			m[arr[i]]++;
			if (m[arr[i]] >= half)
				return 1;
		}

		// get the values from the map
		std::vector<int> values;
		for (auto it = m.begin(); it != m.end(); it++)
		{
			values.emplace_back(it->second);
		}

		// then we sort the values descending
		std::sort(values.begin(), values.end(), [](int x, int y)
							{ return x > y; });

		// now that we have elements with biggest value sorted at the
		// begining of values vector
		int r = 0;
		int minSetLength = 0;
		for (int i = 0; i < values.size(); i++)
		{
			if (r >= half)
				break;
			r += values[i];
			minSetLength++;
		}

		return minSetLength;
	}
};

int main()
{
	Solution s;
	// std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	std::vector<int> arr = {9, 77, 63, 22, 92, 9, 14, 54, 8, 38, 18, 19, 38, 68, 58, 19};
	// std::vector<int> arr = {3, 3, 3, 3, 5, 5, 5, 2, 2, 7};
	std::cout << "ans: " << s.minSetSize(arr) << std::endl;
	return 0;
}