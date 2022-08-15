#include <iostream>
#include <vector>
#include <unordered_map>

class Solution
{
public:
	std::vector<int> res;
	inline std::vector<int> &nextGreaterElement(std::vector<int> &nums1, std::vector<int> &nums2)
	{
		// method 1: O(N ^ 2)
		// runtime : 28ms at the best run

		// for (int i = 0; i < nums1.size(); i++)
		// {
		// 	const auto x = nums1[i];
		// 	for (int j = 0; j < nums2.size(); j++)
		// 	{
		// 		const auto y = nums2[j];
		// 		if (x != y)
		// 			continue;
		// 		while (j < nums2.size() && nums2[j] <= x)
		// 		{
		// 			j++;
		// 		}
		// 		if (j == nums2.size())
		// 			res.push_back(-1);
		// 		else
		// 			res.push_back(nums2[j]);
		// 	}
		// }

		// method 2: using hashmap
		// runtime: 0ms

		createMap(nums2);

		for (int i = 0; i < nums1.size(); i++)
		{
			const auto x = nums1[i];
			res.push_back(m[x]);
		}

		return res;
	}

private:
	std::unordered_map<int, int> m;
	inline void createMap(std::vector<int> &nums2)
	{
		const auto len = nums2.size();
		int prev = -1;
		for (int i = len - 1; i >= 0; i--)
		{
			const auto x = nums2[i];
			m[x] = nextGreater(x, prev);
			prev = x;
		}
	}

	inline int nextGreater(int x, int prev)
	{

		if (prev > x || prev == -1)
		{
			return prev;
		}
		return nextGreater(x, m[prev]);
	}
};

int main()
{
	Solution s;
	std::vector<int> nums1 = {1, 6};
	std::vector<int> nums2 = {1, 2, 3, 4, 5, 6};
	const auto res = s.nextGreaterElement(nums1, nums2);

	// printing
	for (const auto x : res)
	{
		std::cout << x << ", ";
	}
	std::cout << std::endl;

	return 0;
}