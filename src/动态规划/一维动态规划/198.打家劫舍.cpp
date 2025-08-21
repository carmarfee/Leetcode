#include <vector>
using namespace std;

class Solution
{
public:
//DP[i] = 前i个房屋的最大抢劫金额
    class Solution {
public:
    int rob(vector<int> &nums)
    {
        if (nums.empty())
        {
            return 0; // 如果没有房屋，返回0
        }
        if (nums.size() == 1)
        {
            return nums[0]; // 如果只有一个房屋，直接返回其金额
        }

        // 初始化前两个房屋的最大抢劫金额
        int first = nums[0]; // 抢劫第一个房屋
        int second = max(nums[0], nums[1]); // 抢劫第一个或第二个房屋
        //为什么要用max，因为如果抢劫了第一个房屋，就不能抢劫第二个房屋，所以只能选择抢劫第一个或第二个房屋中金额更大的那个。

        // 从第三个房屋开始计算
        for (int i = 2; i < nums.size(); ++i)
        {
            int current = max(second, first + nums[i]); // 当前房屋的最大抢劫金额
            first = second; // 更新前一个房屋的金额
            second = current; // 更新当前房屋的金额
        }

        return second; // 返回最后一个房屋的最大抢劫金额
    }
};
};