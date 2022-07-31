#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

class Solution
{
public:
	inline bool containsDuplicate(std::vector<int> &nums)
	{
		const size_t len = nums.size();
		if (len == 0)
			return false;

		// first approach: using hashmap
		// runtime: 192ms

		// std::unordered_map<int, int> m;

		// int i = 0;
		// for (i = 0; i < len; i++)
		// {
		// 	m[nums[i]] = i;
		// }

		// return m.size() != len;

		// second approach: O(N ^ 2)
		// runtime: time limit exceeded

		// int i = 0;
		// int j = 0;
		// for (i = 0; i < len; i++)
		// {
		// 	for (j = i + 1; j < len; j++)
		// 	{
		// 		if (nums[i] == nums[j])
		// 			return true;
		// 	}
		// }

		// return false;

		// third approach: using sets
		// runtime: 147ms

		// std::unordered_set<int> s(nums.begin(), nums.end());
		// return s.size() != nums.size();

		// fourth approach: using sort
		// runtime: exceeded

		// std::sort(nums.begin(), nums.end());

		// long i = 0;
		// for (i = 0; i < len; i++)
		// {
		// 	if (i == len - 1)
		// 		return false;
		// 	const auto res = binarySearch(nums, i + 1, nums[i]);
		// 	if (res)
		// 		return true;
		// }

		// return false;

		// fifth approach: sort then for loop
		// runtime: 187ms

		// std::sort(nums.begin(), nums.end());
		// int i = 0;
		// for (i = 0; i < len; i++)
		// {
		// 	if (i == len - 1)
		// 		return false;
		// 	if (nums[i] == nums[i + 1])
		// 		return true;
		// }
		// return false;

		// sixth approach : hashmap again :)
		// runtime: 130ms

		std::unordered_map<int, int> m;
		int i = 0;
		for (i = 0; i < len; i++)
		{
			const auto x = nums[i];
			if (m[x] != 0)
				return true; // we found
			if (x >= 0)
				m[x] = x + 1;
			else
				m[x] = x;
		}
		return false;
	}

	bool binarySearch(std::vector<int> v, int lo, int To_Find)
	{
		int hi = v.size() - 1;
		int mid;
		// This below check covers all cases , so need to check
		// for mid=lo-(hi-lo)/2
		while (hi - lo > 1)
		{
			int mid = (hi + lo) / 2;
			if (v[mid] < To_Find)
			{
				lo = mid + 1;
			}
			else
			{
				hi = mid;
			}
		}
		if (v[lo] == To_Find)
		{
			return true;
		}
		else if (v[hi] == To_Find)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

int main()
{
	std::vector<int> nums = {1, 2, 3, 1};
	Solution s;
	std::cout << "response is " << s.containsDuplicate(nums) << std::endl;
	// std::cout << "bin search (1) " << s.find(1, 1, nums, nums.size()) << std::endl;
	return 0;
}