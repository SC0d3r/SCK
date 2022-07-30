#include <iostream>
#include <vector>

class Solution
{
public:
	std::vector<int> sortedSquares(std::vector<int> &nums)
	{
		int lp = 0;								// left pointer
		int rp = nums.size() - 1; // right pointer
		int index = rp;
		std::vector<int> res(rp + 1);
		while (lp != rp)
		{
			int xlp = nums[lp] * nums[lp];
			int xrp = nums[rp] * nums[rp];
			if (xlp >= xrp)
			{
				res[index] = xlp;
				lp++;
				index--;
			}
			else
			{

				res[index] = xrp;
				index--;
				rp--;
			}
		}

		res[0] = nums[rp] * nums[rp];

		return res;
	}
};

int main()
{
	std::vector<int> a = {-1, 0, 1, 2, 3};
	Solution s;
	auto res = s.sortedSquares(a);
	std::cout << "HELLO TO YOU\n";
	for (auto aa : res)
		std::cout << aa << "\n";
	std::cout << std::endl;
	return 0;
}