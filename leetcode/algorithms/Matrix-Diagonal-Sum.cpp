#include <iostream>
#include <vector>

class Solution
{
public:
	inline int diagonalSum(std::vector<std::vector<int>> &mat)
	{
		int sum = 0;
		const auto M = mat.size();
		for (int i = 0; i < M; i++)
		{
			sum += mat[i][i];
			sum += mat[i][M - i - 1];
		}
		if (M % 2 != 0)
			sum -= mat[M / 2][M / 2];

		return sum;
	}
};

int main()
{
	Solution s;
	std::vector<std::vector<int>> mat = {
			{1, 2, 3},
			{4, 5, 6},
			{7, 8, 9}};

	std::cout << "ans: " << s.diagonalSum(mat) << std::endl;
	return 0;
}