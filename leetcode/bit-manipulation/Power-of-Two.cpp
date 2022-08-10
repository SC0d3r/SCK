#include <iostream>
#include <vector>
#include <bitset>

class Solution
{
public:
	bool isPowerOfTwo(int n)
	{
		if (n <= 0)
			return false;

		// method 1: naive approach
		// runtime: 0ms

		// int res = 0;
		// while (res == 0 && n != 1)
		// {
		// 	res = n % 2;
		// 	n = n / 2;
		// }

		// return res == 0;

		// method 2: using bitset
		// runtime: 0ms

		// return std::bitset<32>(n).count() == 1;

		// method 3: (n & (n - 1)) if zero then its multiple of 2

		return (n & (n - 1)) == 0;
	}
};

int main()
{
	Solution so;
	std::cout << "ans: " << so.isPowerOfTwo(32) << std::endl;
	// std::cout << std::bitset<32>(11) << std::endl;
	return 0;
}