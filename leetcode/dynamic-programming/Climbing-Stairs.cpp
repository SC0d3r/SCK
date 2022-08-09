#include <iostream>
#include <vector>
#include <unordered_map>

class Solution
{
public:
	int climbStairs(int n)
	{
		if (n <= 2)
			return n;

		if (m[n] != 0)
		{
			// found in memo
			return m[n];
		}

		return m[n] = climbStairs(n - 1) + climbStairs(n - 2);
	}

private:
	std::unordered_map<int, int> m;
};

int main()
{
	Solution s;
	std::cout << "result: " << s.climbStairs(6) << std::endl;
	return 0;
}