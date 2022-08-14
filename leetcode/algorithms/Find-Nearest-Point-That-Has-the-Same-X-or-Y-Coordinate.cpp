#include <iostream>
#include <vector>

class Solution
{
public:
	inline int nearestValidPoint(int &x, int &y, std::vector<std::vector<int>> &points)
	{
		int min = 1e9;
		int idx = -1;
		const auto len = points.size();

		for (int i = 0; i < len; i++)
		{
			const auto x1 = points[i][0];
			const auto y1 = points[i][1];
			if (x != x1 && y != y1)
				continue;
			const auto dist = abs(x - x1) + abs(y - y1);
			if (dist < min)
			{
				min = dist;
				idx = i;
			}
		}

		return idx;
	}
};

int main()
{
	return 0;
}