#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution
{
public:
	inline std::vector<int> intersect(std::vector<int> &nums1, std::vector<int> &nums2)
	{
		const auto len1 = nums1.size();
		const auto len2 = nums2.size();
		std::vector<int> res;

		// method 1: using two maps
		// runtime: 9ms at the best run

		// int i;
		// std::unordered_map<int, int> m1;
		// for (i = 0; i < len1; i++)
		// {
		// m1[nums1[i]] = m1[nums1[i]] + 1;
		// }

		// std::unordered_map<int, int> m2;
		// for (i = 0; i < len2; i++)
		// {
		// m2[nums2[i]] = m2[nums2[i]] + 1;
		// }

		// for (const auto [key, val] : m2)
		// {
		// const auto val1 = m1[key];
		// if (val1 != 0)
		// {
		// {
		// res.emplace_back(key);
		// }
		// }
		// }

		// return res;

		// method 2 : using two pointers
		// runtime: 5ms at the best run

		int p1 = 0;
		int p2 = 0;
		std::sort(nums1.begin(), nums1.end());
		std::sort(nums2.begin(), nums2.end());

		while (p1 < len1 && p2 < len2)
		{
			const auto x1 = nums1[p1];
			auto x2 = nums2[p2];
			if (x1 == x2)
			{
				res.emplace_back(x1);
				p2++;
			}
			if (x1 > x2)
			{
				p2++;
			}
			else
			{
				p1++;
			}
		}

		return res;
	}
};

int main()
{
	Solution s;
	std::vector<int> nums1 = {5, 4, 9};
	// std::vector<int> nums1 = {1, 2, 2, 1};
	std::vector<int> nums2 = {4, 8, 9, 4, 9};
	// std::vector<int> nums2 = {2, 2};
	std::vector<int> res = s.intersect(nums1, nums2);
	for (const auto x : res)
	{
		std::cout << x << std::endl;
	}
	return 0;
}