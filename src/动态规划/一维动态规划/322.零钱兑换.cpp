#include <vector>
using namespace std;

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, amount + 1); // 初始化为一个不可能的值
        dp[0] = 0; // 0 元需要 0 个硬币
        for (int i = 1; i <= amount; ++i)
        {
            for (int coin : coins)
            {
                if (i - coin >= 0) // 确保不越界
                {
                    dp[i] = min(dp[i], dp[i - coin] + 1); // 状态转移方程
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount]; // 如果 dp[amount] 仍然是初始值，说明无法凑成该金额
    }
};