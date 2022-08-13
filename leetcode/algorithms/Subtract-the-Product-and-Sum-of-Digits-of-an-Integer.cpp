#include <iostream>
#include <string>

class Solution
{
public:
	int subtractProductAndSum(int n)
	{
		// method 1: using string and casting
		// runtime: 0ms

		// const auto str = std::to_string(n);
		// int sum = 0;
		// int mul = 1;
		// for (const auto x : str)
		// {
		// 	const auto xInt = x - '0';
		// 	sum += xInt;
		// 	mul *= xInt;
		// }

		// return mul - sum;

		// method 2: using math
		// runtime: 0ms

		int sum = 0;
		int mul = 1;
		while (n != 0)
		{
			sum += n % 10;
			mul *= n % 10;
			n /= 10;
		}
		return mul - sum;
	}
};

int main()
{
	Solution s;
	std::cout << "ans: " << s.subtractProductAndSum(234) << std::endl;
	return 0;
}