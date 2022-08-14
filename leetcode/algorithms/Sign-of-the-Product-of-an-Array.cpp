#include <iostream>
#include <vector>
#include <numeric>

#define signBit(X) ((X >> 31) && 1)

class Solution
{
public:
	inline int arraySign(std::vector<int> &nums)
	{
		uint8_t sign = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			const auto x = nums[i];
			if (x == 0)
				return 0;
			sign ^= signBit(x);
		}

		return sign == 0 ? 1 : -1;
	}
};

int main()
{
	std::vector<int> nums = {-1, 1, 1};
	Solution s;
	// std::cout << "ans: " << s.arraySign(nums) << std::endl;
	std::cout << "sign: " << signBit(-1) << std::endl;
	return 0;
}