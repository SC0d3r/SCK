#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

struct pair_hash
{
	template <class T1, class T2>
	std::size_t operator()(const std::pair<T1, T2> &pair) const
	{
		return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
	}
};

class Solution
{
public:
	typedef std::pair<int, int> pair;
	std::vector<std::vector<int>> &floodFill(std::vector<std::vector<int>> &image, int sr, int sc, int color)
	{
		const auto m = image.size();
		const auto n = image[0].size();

		std::queue<pair> q;
		q.push(std::make_pair(sr, sc));
		const auto defaultColor = image[sr][sc];
		image[sr][sc] = color; // discover the first one
		std::unordered_map<pair, bool, pair_hash> discovered;
		while (!q.empty())
		{
			const auto x = q.front();
			q.pop();

			// add all the edges to queue and discover them
			const auto p1 = std::make_pair(x.first - 1, x.second);
			const auto p2 = std::make_pair(x.first + 1, x.second);
			const auto p3 = std::make_pair(x.first, x.second - 1);
			const auto p4 = std::make_pair(x.first, x.second + 1);
			// we add this pair to queue
			if (isValid(p1, m, n) && !discovered[p1])
			{
				discovered[p1] = true;
				// if its the same color then change the color
				if (image[p1.first][p1.second] == defaultColor)
				{

					image[p1.first][p1.second] = color;
					q.push(p1);
				}
			}

			if (isValid(p2, m, n) && !discovered[p2])
			{
				discovered[p2] = true;
				if (image[p2.first][p2.second] == defaultColor)
				{

					image[p2.first][p2.second] = color;
					q.push(p2);
				}
			}

			if (isValid(p3, m, n) && !discovered[p3])
			{

				discovered[p3] = true;
				if (image[p3.first][p3.second] == defaultColor)
				{

					image[p3.first][p3.second] = color;
					q.push(p3);
				}
			}

			if (isValid(p4, m, n) && !discovered[p4])
			{

				discovered[p4] = true;
				if (image[p4.first][p4.second] == defaultColor)
				{

					image[p4.first][p4.second] = color;
					q.push(p4);
				}
			}
		}
		return image;
	}

private:
	bool
	isValid(const pair &p, int m, int n)
	{
		return p.first >= 0 && p.first < m && p.second >= 0 && p.second < n;
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