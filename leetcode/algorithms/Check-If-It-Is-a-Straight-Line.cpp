#include <iostream>
#include <vector>

class Solution
{
public:
	inline bool checkStraightLine(std::vector<std::vector<int>> &coordinates)
	{
		// creating the line formula:
		// y - y1 = (y2 - y1)/(x2 - x1) (x - x1);
		// we rearange that into bellow formula:
		// (x2 - x1)(y - y1) - (y2 - y1)(x - x1) = 0;
		// so every (x,y) which makes the above formula zero is part of the line
		const auto xy1 = coordinates[0];
		const auto xy2 = coordinates[1];
		const auto x1 = xy1[0];
		const auto y1 = xy1[1];
		const auto x2 = xy2[0];
		const auto y2 = xy2[1];
		const auto mNum = (y2 - y1);
		const auto mDenom = (x2 - x1);
		const auto f = [&](int x, int y)
		{ return mDenom * (y - y1) - mNum * (x - x1); };

		// now we check if every point is on the line
		const auto len = coordinates.size();
		for (int i = 2; i < len; i++)
		{
			const auto xy = coordinates[i];
			const auto x = xy[0];
			const auto y = xy[1];
			if (f(x, y) != 0)
				return false;
		}

		return true;
	}
};

int main()
{
	std::vector<std::vector<int>> coords = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 7}};
	Solution s;
	std::cout << "ans: " << s.checkStraightLine(coords) << std::endl;
	return 0;
}