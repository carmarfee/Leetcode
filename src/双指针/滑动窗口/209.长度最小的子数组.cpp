#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int right = 0, left = 0;
        int sum = 0;             // 当前窗口的和
        int minLength = INT_MAX; // 最小长度初始化为最大值
        while (right < nums.size())
        {
            sum += nums[right];
            right++;
            while (sum >= target)
            {
                minLength = min(minLength, right - left); // 更新最小长度
                sum -= nums[left];                        // 缩小窗口
                left++;
            }
        }
        return minLength == INT_MAX ? 0 : minLength; // 如果没有满足条件的子数组，返回0
    }
};