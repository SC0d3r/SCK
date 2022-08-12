#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
	inline double average(std::vector<int> &salary)
	{
		// method 1: which is O(nlogn) cause of sorting
		// runtime : 0ms

		// const auto len = salary.size() - 2;
		// std::sort(salary.begin(), salary.end());
		// auto total = 0.0;
		// for (int i = 1; i <= len; i++)
		// 	total += salary[i];

		// return total / len;

		// method 2: just one for loop
		// runtime: 0ms 6.9MB less than 96% memory usage

		const auto len = salary.size();
		int min = 1e9;
		int max = -1e9;
		double total = 0.0;

		for (int i = 0; i < len; i++)
		{
			const auto x = salary[i];
			total += x;
			if (x < min)
				min = x;
			if (x > max)
				max = x;
		}

		return (total - (min + max)) / (len - 2);
	}
};

int main()
{
	Solution s;
	std::vector<int> salary = {1000, 2000, 4000};
	std::cout << "average: " << s.average(salary) << std::endl;
	return 0;
}