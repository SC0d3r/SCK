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

		// int res = 0;
		// for (int i = 0; i < 32; i++)
		// {
		// 	if (n == 0)
		// 		return res;
		// 	const auto x = n >> 1;
		// 	if (x << 1 != n)
		// 		res++;
		// 	n = x;
		// }

		// return res;

		// method 3: crazy stuff
		// runtime: ??ms

		n = n - ((n >> 1) & 0x55555555);
		n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
		n = (n + (n >> 4)) & 0x0F0F0F0F;
		n = n + (n >> 8);
		n = n + (n >> 16);
		return n & 0x0000003F;
	}
};

int main()
{
	Solution s;
	uint32_t n = 7;
	std::cout << "count: " << s.hammingWeight(n) << std::endl;
	return 0;
}