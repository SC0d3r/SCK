#include <iostream>
#include <bitset>

class Solution
{
public:
	inline int hammingWeight(uint32_t &n)
	{
		// method 1: using bitset
		// runtime: 0ms

		// return std::bitset<32>(n).count();

		// method 2: using bit shifting
		// runtime: 0ms

		int res = 0;
		for (int i = 0; i < 32; i++)
		{
			if (n == 0)
				return res;
			const auto x = n >> 1;
			if (x << 1 != n)
				res++;
			n = x;
		}

		return res;
	}
};

int main()
{
	Solution s;
	std::cout << "count: " << s.hammingWeight(7) << std::endl;
	return 0;
}