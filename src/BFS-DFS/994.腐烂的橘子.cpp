#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        if (grid.empty() || grid[0].empty())
        {
            return 0; // 如果网格为空，返回0
        }
        int rows = grid.size();
        int cols = grid[0].size();
        int freshCount = 0; // 新鲜橘子的数量
        int minutes = 0; // 计时器，记录腐烂所需的分钟数
        queue<pair<int, int>> q; // 用于存储腐烂橘子的坐标
        //初始化队列
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j] == 1)
                {
                    freshCount++; // 统计新鲜橘子的数量
                }
                else if (grid[i][j] == 2)
                {
                    q.push({i, j}); // 将腐烂橘子的坐标加入队列
                }
            }
        }

        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; // 四个方向
        while(!q.empty() && freshCount > 0)
        {
            int n = q.size(); // 当前轮次腐烂橘子的数量
            for (int i = 0; i < n; i++)
            {
                pair<int,int> pos = q.front();
                q.pop();
                int x = pos.first;
                int y = pos.second;
                for (auto dir : directions)
                {
                    int newX = x + dir[0];
                    int newY = y + dir[1];
                    // 检查新坐标是否在网格内且是新鲜橘子
                    if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && grid[newX][newY] == 1)
                    {
                        grid[newX][newY] = 2; // 将新鲜橘子变为腐烂橘子
                        freshCount--; // 新鲜橘子数量减少
                        q.push({newX, newY}); // 将新腐烂橘子的坐标加入队列
                    }
                }
            }
            minutes++; // 每次循环代表一轮腐烂
        }
        return freshCount == 0 ? minutes : -1; // 如果所有新鲜橘子都腐烂了，返回分钟数，否则返回-1
    }
};