#include <iostream>
#include <vector>
#include <algorithm> // for std::max and std::min

class Solution
{
public:
    int maxProduct(std::vector<int> &nums)
    {
        if (nums.empty())
        {
            return 0;
        }

        // 初始化结果以及当前的最大/最小乘积
        int result = nums[0];
        int max_prod = nums[0];
        int min_prod = nums[0];

        // 从第二个元素开始遍历
        for (int i = 1; i < nums.size(); ++i)
        {
            int current_num = nums[i];

            // 在更新 max_prod 之前，保存旧的 max_prod
            // 因为计算 min_prod 时需要用到它
            int old_max_prod = max_prod;

            // 更新以当前数字结尾的子数组的最大乘积
            max_prod = std::max({current_num,
                                 current_num * old_max_prod,
                                 current_num * min_prod});

            // 更新以当前数字结尾的子数组的最小乘积
            min_prod = std::min({current_num,
                                 current_num * old_max_prod,
                                 current_num * min_prod});

            // 更新全局最大乘积
            result = std::max(result, max_prod);
        }

        return result;
    }
};