#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <limits.h>

static inline uint32_t rotl32(uint32_t n, unsigned int c)
{
	const unsigned int mask = (CHAR_BIT * sizeof(n) - 1); // assumes width is a power of 2.

	// assert ( (c<=mask) &&"rotate by type width or more");
	c &= mask;
	return (n << c) | (n >> ((-c) & mask));
}

static inline uint16_t count(uint32_t n)
{
	uint16_t res = 0;
	while (n != 0)
	{
		n = n & (n - 1);
		res++;
	}
	return res;
}

class Solution
{
public:
	uint32_t reverseBits(uint32_t n)
	{
		// method 1:
		// runtime: 0ms

		// auto str = std::bitset<32>(n);
		// recur(str, 0, str.size() - 1);
		// return str.to_ulong();

		// method 2: using shifting and rotating
		// runtime: ??ms

		const auto low = n & 0xffff;
		const auto high = n >> 16;
		const auto xorRes = low ^ high;
		return rotl32(xorRes, count(xorRes));
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