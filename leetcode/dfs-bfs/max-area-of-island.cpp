#include <iostream>
#include <vector>

class Solution
{
public:
    inline int maxAreaOfIsland(std::vector<std::vector<int>> &grid)
    {
        const auto m = grid.size();
        const auto n = grid[0].size();
        int max = 0;
        int i = 0;
        int j = 0;
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                max = std::max(max, getArea(grid, m, n, i, j));
            }
        }
        return max;
    }

private:
    inline int getArea(std::vector<std::vector<int>> &grid, int m, int n, int i, int j)
    {

        if (i < 0 || i >= m || j < 0 || j >= n)
            return 0;

        // 2 is the visited number for the cells in the grid
        if (grid[i][j] == 0 || grid[i][j] == 2)
            return 0;

        grid[i][j] = 2; // visited

        return 1 + getArea(grid, m, n, i + 1, j) +
               getArea(grid, m, n, i - 1, j) +
               getArea(grid, m, n, i, j + 1) +
               getArea(grid, m, n, i, j - 1);
    }
};

int main()
{
    Solution s;
    std::vector<std::vector<int>> grid =
        {{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
         {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
         {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
         {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};

    std::cout << "area: " << s.maxAreaOfIsland(grid) << std::endl;
    return 0;
}
