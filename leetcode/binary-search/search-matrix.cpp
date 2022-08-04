#include <iostream>
#include <vector>

class Solution
{
public:
	bool searchMatrix(std::vector<std::vector<int>> &matrix, int target)
	{
		const auto M = matrix.size();
		const auto N = matrix[0].size();
		// flatten the matrix
		std::vector<int> flat;
		int i = 0;
		int j = 0;
		for (i = 0; i < M; i++)
		{
			for (j = 0; j < N; j++)
			{
				flat.emplace_back(matrix[i][j]);
			}
		}

		// now we binary search the flatten vector
		int l = 0;
		int r = M * N;
		while (l < r)
		{
			int pv = (l + r) / 2;
			const auto x = flat[pv];
			if (x == target)
				return true;
			if (x > target)
			{
				r = pv;
			}
			else
			{
				l = pv + 1;
			}
		}

		return false;
	}
};

int main()
{
	std::vector<std::vector<int>> m = {{1, 3, 5, 7},
																		 {10, 11, 16, 20},
																		 {23, 30, 34, 60}};
	Solution s;
	std::cout << "Contains: " << (s.searchMatrix(m, 3) ? "TRUE" : "FALSE")
						<< "\n";
	return 0;
}
