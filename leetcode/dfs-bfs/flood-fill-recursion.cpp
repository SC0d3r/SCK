#include <iostream>
#include <vector>

class Solution
{
public:
	inline void solve(std::vector<std::vector<int>> &image, int sr, int sc, int defaultColor, int newColor)
	{
		const auto m = image.size();
		const auto n = image[0].size();
		if (!isValid(sr, sc, m, n))
			return;

		const auto color = image[sr][sc];
		if (color != defaultColor)
			return;
		if (color == newColor)
			return;

		image[sr][sc] = newColor;

		solve(image, sr - 1, sc, defaultColor, newColor);
		solve(image, sr + 1, sc, defaultColor, newColor);
		solve(image, sr, sc - 1, defaultColor, newColor);
		solve(image, sr, sc + 1, defaultColor, newColor);
	}

	inline std::vector<std::vector<int>> &floodFill(std::vector<std::vector<int>> &image, int sr, int sc, int color)
	{
		const auto defaultColor = image[sr][sc];
		solve(image, sr, sc, defaultColor, color);
		return image;
	}

private:
	inline bool isValid(int sr, int sc, int m, int n)
	{
		return sr >= 0 && sr < m && sc >= 0 && sc < n;
	}
};

int main()
{
	Solution s;
	std::vector<std::vector<int>> image = {{1, 1, 1},
																				 {1, 1, 0},
																				 {1, 0, 1}};
	const auto res = s.floodFill(image, 1, 1, 2);

	for (const auto xs : res)
	{
		for (const auto x : xs)
		{
			std::cout << x << ", ";
		}
		std::cout << std::endl;
	}
	return 0;
}