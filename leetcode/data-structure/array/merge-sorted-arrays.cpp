#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution
{
public:
	void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n)
	{
		int i = 0;

		// approach 1: this works but slow
		// runtime: 32ms

		// copy nums2 to nums1
		// for (i = 0; i < n; i++)
		// {
		// 	nums1[m + i] = nums2[i];
		// }

		// int j = 0;
		// for (i = m; i < m + n; i++)
		// {
		// 	const auto x2 = nums1[i];
		// 	int p = i;
		// 	for (j = i - 1; j >= 0; j--)
		// 	{
		// 		const auto x1 = nums1[j];
		// 		if (x2 < x1)
		// 		{
		// 			// remove x2
		// 			nums1.erase(nums1.begin() + p);
		// 			// insert x2
		// 			nums1.insert(nums1.begin() + j, x2);
		// 			p -= 1;
		// 		}
		// 	}
		// }

		// appraoch 2 : merge sort
		// runtime: 0ms faster than the 100% of the submissions!!
		// std::vector<int> res(m + n);
		std::vector<int> *res = new std::vector<int>(m + n);
		int p1 = 0;
		int p2 = 0;
		int pRes = 0;
		while (p1 < m && p2 < n)
		{
			const auto x1 = nums1[p1];
			const auto x2 = nums2[p2];
			if (x1 < x2)
			{
				res->at(pRes++) = x1;
				// res[pRes++] = x1;
				p1++;
			}
			else
			{
				res->at(pRes++) = x2;
				// res[pRes++] = x2;
				p2++;
			}
		}
		// copy the rest
		if (p1 < m)
		{
			// means there are remaining in p1
			for (int j = p1; j < m; j++)
			{
				// res[pRes++] = nums1[j];
				res->at(pRes++) = nums1[j];
			}
		}
		if (p2 < n)
		{
			// means there are remaining in p2
			for (int j = p2; j < n; j++)
			{

				// res[pRes++] = nums2[j];
				res->at(pRes++) = nums2[j];
			}
		}

		nums1 = *res;
	}
};

int main()
{
	// std::vector<int> nums1 = {0};
	std::vector<int> nums1 = {4, 5, 6, 0, 0, 0};
	std::vector<int> nums2 = {1, 2, 3};
	Solution s;
	s.merge(nums1, 3, nums2, 3);
	for (const auto x : nums1)
	{
		std::cout << x << "\n";
	}

	return 0;
}