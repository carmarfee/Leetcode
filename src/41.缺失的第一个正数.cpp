#include <vector>
#include <algorithm> // for std::max and std::min

class Solution
{
public:
    int firstMissingPositive(std::vector<int> &nums)
    {
        int n = nums.size();

        // 第一步：原地交换，将数字 k 放到索引 k-1 的位置
        for (int i = 0; i < n; ++i)
        {
            // 当 nums[i] 是有效数字，且没有在正确的位置时，循环交换
            // nums[i] != nums[nums[i] - 1] 是为了防止有重复数字时死循环
            while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1])
            {
                std::swap(nums[i], nums[nums[i] - 1]);
            }
        }

        // 第二步：查找第一个 nums[i] != i + 1 的位置
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] != i + 1)
            {
                return i + 1;
            }
        }

        // 如果 [1, n] 都存在，则缺失的是 n + 1
        return n + 1;
    }
};