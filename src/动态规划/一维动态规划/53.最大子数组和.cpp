#include <vector>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        if (nums.empty())
        {
            return 0; // 如果数组为空，返回0
        }
        int maxSum = nums[0]; // 初始化最大子数组和为第一个元素

        vector<int> dp(nums.size() + 1, 0); // 初始化 dp 数组
        // dp[i]表示以nums[i]结尾的最大子数组和
        // 状态转移方程dp[i]=max(dp[i-1]+nums[i], nums[i])
        dp[0] = nums[0]; // 第一个元素的最大子数组和就是它本身
        for (int i = 1; i < nums.size(); i++)
        {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]); // 状态转移方程
            maxSum = max(maxSum, dp[i]);               // 更新最大子数组和
        }
        return maxSum; // 返回最大子数组和
    }
};