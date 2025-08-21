#include <vector>
#include <queue>
using namespace std;

class Solution
{
private:
    void dfs(vector<vector<char>> &grid, int i, int j)
    {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0')
        {
            return; // 越界或不是岛屿，直接返回
        }
        grid[i][j] = '0'; // 标记为已访问
        // 递归访问四个方向
        dfs(grid, i + 1, j); // 下
        dfs(grid, i - 1, j); // 上
        dfs(grid, i, j + 1); // 右
        dfs(grid, i, j - 1); // 左
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        if (grid.empty() || grid[0].empty())
        {
            return 0; // 如果网格为空，返回0
        }

        int rows = grid.size();
        int cols = grid[0].size();
        int islandCount = 0;

        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (grid[i][j] == '1') // 找到一个岛屿
                {
                    islandCount++;
                    dfs(grid, i, j); // 深度优先搜索标记这个岛屿
                }
            }
        }
        return islandCount; // 返回岛屿数量
    }
};

class Solution
{
private:
    void bfs(vector<vector<char>> &grid, int i, int j)
    {
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = '0'; // 标记为已访问

        while (!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();

            // 访问四个方向
            if (x + 1 < grid.size() && grid[x + 1][y] == '1')
            {
                q.push({x + 1, y});
                grid[x + 1][y] = '0';
            }
            if (x - 1 >= 0 && grid[x - 1][y] == '1')
            {
                q.push({x - 1, y});
                grid[x - 1][y] = '0';
            }
            if (y + 1 < grid[0].size() && grid[x][y + 1] == '1')
            {
                q.push({x, y + 1});
                grid[x][y + 1] = '0';
            }
            if (y - 1 >= 0 && grid[x][y - 1] == '1')
            {
                q.push({x, y - 1});
                grid[x][y - 1] = '0';
            }
        }
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        if (grid.empty() || grid[0].empty())
        {
            return 0; // 如果网格为空，返回0
        }

        int rows = grid.size();
        int cols = grid[0].size();
        int islandCount = 0;

        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (grid[i][j] == '1') // 找到一个岛屿
                {
                    islandCount++;
                    bfs(grid, i, j); // 广度优先搜索标记这个岛屿
                }
            }
        }
        return islandCount; // 返回岛屿数量
    }
};