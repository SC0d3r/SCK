#include <iostream>
#include <vector>
#include <string>

class Solution
{
public:
	inline std::vector<std::vector<int>> matrixReshape(std::vector<std::vector<int>> &mat, int r, int c)
	{
		const auto firstRow = mat[0];
		const auto m = mat.size();
		const auto n = firstRow.size();

		if (m * n != r * c)
			return mat;

		std::vector<std::vector<int>> res;

		// method 1
		// runtime: 12ms

		// std::vector<int> flatten;
		// for (const auto xs : mat)
		// {
		// 	for (const auto x : xs)
		// 	{
		// 		flatten.emplace_back(x);
		// 	}
		// }

		// int k = 0;
		// int j = 0;
		// while (k < r)
		// {
		// 	std::vector<int> row;
		// 	for (int i = 0; i < c; i++)
		// 	{
		// 		row.emplace_back(flatten[i + j]);
		// 	}
		// 	res.emplace_back(row);
		// 	k++;
		// 	j += c;
		// }

		// method 2:
		// runtime: 9ms at the best run

		int i = 0;
		int j = 0;
		for (i = 0; i < r; i++)
		{
			std::vector<int> row;
			for (j = 0; j < c; j++)
			{
				row.emplace_back(mat[pi][pj]);
				incP(m, n);
			}
			res.emplace_back(row);
		}

		return res;
	}

private:
	int pi = 0;
	int pj = 0;

	inline void incP(int m, int n)
	{
		pj = (pj + 1) % n;
		if (pj == 0)
			pi++;
	}
};

int main()
{
	std::vector<std::vector<int>> mat = {{1, 2}, {3, 4}};
	Solution s;
	const auto res = s.matrixReshape(mat, 4, 1);

	for (const auto xs : res)
	{
		for (int i = 0; i < xs.size(); i++)
		{
			const auto len = xs.size();
			std::string t = "";
			if (i != len - 1)
			{
				t = ", ";
			}
			std::cout << xs[i] << t;
		}
		std::cout << "\n";
	}

	return 0;
}