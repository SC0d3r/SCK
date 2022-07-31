#include <iostream>
#include <vector>
#include <unordered_map>

class Solution
{
public:
	inline std::vector<int> twoSum(std::vector<int> &numbers, int target)
	{
		const auto len = numbers.size();

		// first approach:
		// runtime: time limit exceeded

		// int diff = 0;
		// for (int i = 0; i < len; i++)
		// {
		// 	const auto x = numbers[i];
		// 	if (x > target)
		// 		continue;
		// 	diff = target - x;
		// 	for (int j = i + 1; j < len; j++)
		// 	{
		// 		if (numbers[j] == diff)
		// 			return {i + 1, j + 1};
		// 	}
		// }
		// // not found
		// return {0, 0};

		// second appraoch: (hash map)
		// we use map to find the index of the diff
		// runtime: 15ms

		int diff;
		std::unordered_map<int, int> m;
		int i; // magically bringing this int i definition out of the for loop
		// makes the runtime: 28ms -> 15ms
		for (i = 0; i < len; i++)
		{
			m[numbers[i]] = i; // elemnt to index map
		}

		for (i = 0; i < len; i++)
		{
			const auto x = numbers[i];

			diff = target - x;
			auto index = m[diff];
			if (index != 0)
				return {i + 1, index + 1};
		}

		// third approach: (two pointers)
		// cause the array is soreted we can use this
		// approach otherwise we had to user the hashmap
		// runtime: 22ms

		// int i = 0;
		// int j = len - 1;
		// while (i < j)
		// {
		// 	// const auto x = numbers[i];
		// 	// const auto y = numbers[j];
		// 	const auto sum = numbers[i] + numbers[j];
		// 	if (sum == target)
		// 		return {i + 1, j + 1};
		// 	if (sum < target)
		// 		i++;
		// 	else
		// 		j--;
		// }

		return {0, 0};
	}
};

int main()
{
	std::vector<int> nums = {2, 7, 11, 15};
	int target = 9;
	Solution s;
	auto res = s.twoSum(nums, target);
	for (auto x : res)
	{
		std::cout << x << "\n";
	}
	return 0;
}