#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 1)
        {
            return 0; // 如果数组长度小于等于1，直接返回0
        }
        // dp[i]表示到达位置i的最小跳跃次数
        unordered_map<int, int> dp;
        dp[0] = 0; // 起点不需要跳跃
        dp[1] = 1; // 从起点到第一个位置需要1次跳跃
        for (int i = 1; i < n; ++i)
        {
            for (int j = 1; j <= nums[i]; ++j)
            {
                if(dp.find(i + j) == dp.end())
                {
                    dp[i + j] = INT_MAX; // 初始化为最大值
                }
                dp[i+j]=min(dp[i+j], dp[i] + 1); // 更新到达位置i+j的最小跳跃次数
            }
        }
        return dp[n - 1]; // 返回到达最后一个位置的最小跳跃次数
    }
};

class Solution
{
public:
    int jump(std::vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 1)
        {
            return 0;
        }

        int jumps = 0;
        int current_reach = 0;  // 当前这一跳能到达的最远位置
        int farthest_reach = 0; // 在当前范围内，下一步能到达的最远位置

        // 遍历到倒数第二个元素，因为到达 n-1 就结束了
        for (int i = 0; i < n - 1; ++i)
        {
            // 更新从当前[0, current_reach]范围内出发，下一步能到达的最远位置
            farthest_reach = std::max(farthest_reach, i + nums[i]);

            // 如果到达了当前这一跳的边界，则必须进行下一次跳跃
            if (i == current_reach)
            {
                jumps++;
                current_reach = farthest_reach;

                // 优化：如果下一步已经可以覆盖终点，可以提前结束
                if (current_reach >= n - 1)
                {
                    break;
                }
            }
        }

        return jumps;
    }
};