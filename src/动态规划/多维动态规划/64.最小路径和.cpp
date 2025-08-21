#include <vector>
using namespace std;

// 状态转移方程: dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1])
class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        if (grid.empty() || grid[0].empty())
        {
            return 0;
        }

        int rows = grid.size();
        int cols = grid[0].size();

        // 步骤3: 初始化第一行
        // 从 (0,1) 开始，每个格子的最小路径和等于它左边格子的路径和加上它自己的值
        for (int j = 1; j < cols; ++j)
        {
            grid[0][j] += grid[0][j - 1];
        }

        // 步骤3: 初始化第一列
        // 从 (1,0) 开始，每个格子的最小路径和等于它上方格子的路径和加上它自己的值
        for (int i = 1; i < rows; ++i)
        {
            grid[i][0] += grid[i - 1][0];
        }

        // 步骤4: 从左到右，从上到下，填充剩余的格子
        for (int i = 1; i < rows; ++i)
        {
            for (int j = 1; j < cols; ++j)
            {
                // 步骤2: 状态转移方程
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            }
        }

        // 最终右下角的格子 (grid[rows-1][cols-1]) 就存储着到达它的最小路径和
        return grid[rows - 1][cols - 1];
    }
};