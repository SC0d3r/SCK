#include <iostream>
#include <unordered_map>

class Solution
{
public:
	inline bool isHappy(int n)
	{
		const auto res = calc(n);
		if (res == 1)
			return true;
		if (m[res])
			return false;
		m[n] = res + 1;
		return isHappy(res);
	}

private:
	std::unordered_map<int, int> m;
	inline int calc(int n) const
	{
		int res = 0;
		while (n != 0)
		{
			const auto x = n % 10;
			res += x * x;
			n /= 10;
		}
		return res;
	}
};

int main()
{
	Solution s;
	std::cout << "ans: " << s.isHappy(19) << std::endl;
	return 0;
}