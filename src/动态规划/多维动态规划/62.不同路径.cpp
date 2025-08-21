#include <iostream>
#include <vector>
using namespace std;
// dp[i][j]表示到达i,j的路径条数
// 状态转移方程: dp[i][j] = min(dp[i-1][j], dp[i][j-1])
// 确定初始递推条件:dp[0][j] = 1, dp[i][0] = 1
// 计算顺序:自底向上
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        if(m <= 0 || n <= 0)
        {
            return 0;
        }
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};