#include <iostream>
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

// this is just for testing
bool isBadVersion(int n)
{
	std::cout << "api call\n";
	return n == 4;
}

class Solution
{
public:
	int firstBadVersion(int n)
	{
		// these long is cause of overflows in leetcode
		// they use big numbers :+|
		long min = 0;
		long max = n;
		// we should reduce the api calls
		while (true)
		{
			long pv = (min + max) / 2;
			auto isBad = isBadVersion(pv);
			if ((max - min) == 1)
				return max;
			if (isBad)
			{
				// we should check the before ones
				// to find the first bad version
				max = pv;
			}
			else
			{
				// we should go forward to find the first bad one
				min = pv;
			}
		}
	}
};

int main()
{
	Solution s;
	std::cout << "fist bad one is " << s.firstBadVersion(5) << std::endl;
}