#include <iostream>
#include <string>
#include <vector>
#include <bitset>

class Solution
{
public:
	inline uint32_t reverseBits(uint32_t n)
	{
		// method 1:
		// runtime: 0ms

		// auto str = std::bitset<32>(n);
		// recur(str, 0, str.size() - 1);
		// return str.to_ulong();

		// method 2: bit manipulation
		// runtime: 0ms

		n = (n & 0x55555555) << 1 | (n >> 1) & 0x55555555;
		n = (n & 0x33333333) << 2 | (n >> 2) & 0x33333333;
		n = (n & 0x0F0F0F0F) << 4 | (n >> 4) & 0x0F0F0F0F;
		n = (n << 24) | ((n & 0xFF00) << 8) |
				((n >> 8) & 0xFF00) | (n >> 24);
		return n;
	}

	inline void recur(std::bitset<32> &str, int i, int j)
	{
		if (i >= j)
			return;

		// swap
		if (str[i] != str[j])
		{
			str[i].flip();
			str[j].flip();
		}

		recur(str, i + 1, j - 1);
	}
};

int main()
{
	Solution s;
	std::cout << "result: " << s.reverseBits(43261596) << std::endl;
	return 0;
}