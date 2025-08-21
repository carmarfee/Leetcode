#include <vector>
#include <unordered_map>
#include <algorithm> // for std::max and std::min
using namespace std;

class Solution
{
public:
    long long maxProfit(vector<int> &prices, vector<int> &strategy, int K)
    {
        int n = prices.size();

        // prices[i] 的前缀和
        long long f[n + 1];
        f[0] = 0;
        for (int i = 1; i <= n; i++)
            f[i] = f[i - 1] + prices[i - 1];

        // prices[i] * strategy[i] 的前缀和
        long long g[n + 1];
        g[0] = 0;
        for (int i = 1; i <= n; i++)
            g[i] = g[i - 1] + prices[i - 1] * strategy[i - 1];

        long long ans = g[n];
        // 枚举要修改的区间的末尾
        for (int i = K; i <= n; i++)
        {
            long long v = g[n];
            // 撤回原来的利润
            v -= g[i] - g[i - K];
            // 加上后半段的利润
            v += f[i] - f[i - K / 2];
            ans = max(ans, v);
        }
        return ans;
    }
};