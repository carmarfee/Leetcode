#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        //dp[i]表示选择在前i天内的最大利润
        //状态转移方程: dp[i] = max(dp[i-1], prices[i] - min_price)
        if (prices.empty())
        {
            return 0; // 如果没有价格数据，返回0
        }
        int min_price = prices[0]; // 初始化最小价格为第一天的价格
        int max_profit = 0; // 初始化最大利润为0
        for (int i = 1; i < prices.size(); i++)
        {
            min_price = min(min_price, prices[i]); // 更新最小价格
            max_profit = max(max_profit, prices[i] - min_price); // 更新最大利润
        }
        if(max_profit < 0)
        {
            return 0; // 如果最大利润小于0，返回0
        }
        return max_profit; // 返回最大利润
    }
};