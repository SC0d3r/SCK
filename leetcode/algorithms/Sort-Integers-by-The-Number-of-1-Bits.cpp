#include <iostream>
#include <vector>
#include <algorithm>

int count1Bits(int x)
{
	int count = 0;
	while (x != 0)
	{
		x = x & (x - 1);
		count++;
	}
	return count;
}

bool comp(const int &a, const int &b)
{
	const auto aBits = count1Bits(a);
	const auto bBits = count1Bits(b);
	if (aBits == bBits)
		return a < b;
	return aBits < bBits;
}

class Solution
{
public:
	std::vector<int> &sortByBits(std::vector<int> &arr)
	{
		std::sort(arr.begin(), arr.end(), comp);
		return arr;
	}
};

int main()
{
	std::vector<int> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8};
	Solution s;
	const auto res = s.sortByBits(arr);
	for (const auto x : res)
		std::cout << x << ", ";
	std::cout << std::endl;
	return 0;
}
