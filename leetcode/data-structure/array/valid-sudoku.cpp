#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
	inline bool isValidSudoku(std::vector<std::vector<char>> &board)
	{
		std::vector<char> seen;
		// rows
		for (int i = 0; i < 9; i++)
		{

			seen.clear();
			// std::vector<char> seen;
			for (int j = 0; j < 9; j++)
			{
				const auto x = board[i][j];

				if (x == '.')
					continue;
				if (std::find(seen.begin(), seen.end(), x) != seen.end())
				{
					// found
					return false;
				}
				seen.emplace_back(x);
			}
		}

		// cols
		for (int i = 0; i < 9; i++)
		{
			// std::vector<char> seen;
			seen.clear();
			for (int j = 0; j < 9; j++)
			{
				const auto x = board[j][i];

				if (x == '.')
					continue;
				if (std::find(seen.begin(), seen.end(), x) != seen.end())
				{
					// found
					return false;
				}
				seen.emplace_back(x);
			}
		}

		// check if the 3 x 3 squares are valid
		for (int k = 0; k < 9; k += 3)
		{
			for (int i = 0; i < 9; i += 3)
			{
				// std::vector<char> seen;
				seen.clear();
				for (int j = 0; j < 3; j++)
				{
					for (int t = 0; t < 3; t++)
					{
						const auto x = board[k + j][i + t];

						if (x == '.')
							continue;
						if (std::find(seen.begin(), seen.end(), x) != seen.end())
						{
							// found
							return false;
						}
						seen.emplace_back(x);
					}
				}
			}
		}

		return true;
	}
};

int main()
{
	std::vector<std::vector<char>> m =
			{{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
			 {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
			 {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
			 {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
			 {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
			 {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
			 {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
			 {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
			 {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

	std::vector<std::vector<char>> m2 =
			{{'8', '3', '.', '.', '7', '.', '.', '.', '.'},
			 {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
			 {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
			 {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
			 {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
			 {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
			 {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
			 {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
			 {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

	std::vector<std::vector<char>> m3 =
			{{'.', '.', '4', '.', '.', '.', '6', '3', '.'},
			 {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
			 {'5', '.', '.', '.', '.', '.', '.', '9', '.'},
			 {'.', '.', '.', '5', '6', '.', '.', '.', '.'},
			 {'4', '.', '3', '.', '.', '.', '.', '.', '1'},
			 {'.', '.', '.', '7', '.', '.', '.', '.', '.'},
			 {'.', '.', '.', '5', '.', '.', '.', '.', '.'},
			 {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
			 {'.', '.', '.', '.', '.', '.', '.', '.', '.'}};
	Solution s;
	std::cout << "is valid: " << s.isValidSudoku(m3) << "\n";
	return 0;
}