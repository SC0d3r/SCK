#include <iostream>
#include <vector>

class Solution
{
public:
	typedef std::pair<int, int> pair;
	inline int orangesRotting(std::vector<std::vector<int>> &grid)
	{
		const auto M = grid.size();
		const auto N = grid[0].size();

		// method 1:
		// runtime: 4ms faster than 93% of submissions!

		int ones = 0;
		int i = 0;
		int j = 0;
		std::vector<pair> patch;
		for (i = 0; i < M; i++)
		{
			for (j = 0; j < N; j++)
			{
				if (grid[i][j] == 1)
					ones++;
				if (grid[i][j] == 2)
					patch.emplace_back(i, j);
			}
		}

		int minutes = 0;

		while (patch.size() != 0)
		{
			if (ones == 0)
				break;
			const auto ptch = patch;
			patch.clear();

			bool didUpdate = false;
			for (const auto [i, j] : ptch)
			{

				if ((i - 1) >= 0 && grid[i - 1][j] == 1)
				{
					didUpdate = true;
					ones--;
					grid[i - 1][j] = 2;
					patch.emplace_back(i - 1, j);
				}

				if ((i + 1) < M && grid[i + 1][j] == 1)
				{

					didUpdate = true;
					ones--;
					grid[i + 1][j] = 2;
					patch.emplace_back(i + 1, j);
				}

				if ((j - 1) >= 0 && grid[i][j - 1] == 1)
				{

					didUpdate = true;
					ones--;
					grid[i][j - 1] = 2;
					patch.emplace_back(i, j - 1);
				}

				if ((j + 1) < N && grid[i][j + 1] == 1)
				{

					didUpdate = true;
					ones--;
					grid[i][j + 1] = 2;
					patch.emplace_back(i, j + 1);
				}
			}

			if (didUpdate)
				minutes++;
		}

		if (ones == 0)
			return minutes;
		return -1;
	}
};

int main()
{
	Solution s;
	std::vector<std::vector<int>> grid = {{2, 1, 1},
																				{0, 1, 1},
																				{1, 0, 1}};

	std::cout << "Minutes: " << s.orangesRotting(grid) << std::endl;
	return 0;
}