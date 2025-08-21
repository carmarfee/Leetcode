#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int>remainder_map; // 存储前缀和sum mod k 的结果,<前缀和 mod k，下标>
        int current_sum = 0;
        remainder_map[0] = -1; // 处理刚好前缀和sum mod k== 0 的情况
        for (int i = 0; i < nums.size(); i++)
        {
            current_sum += nums[i];
            if (remainder_map.count(current_sum % k))
            {
                // 如果当前前缀和 mod k 的结果已经存在，且下标差大于等于2
                if (i - remainder_map[current_sum % k] > 1)
                {
                    return true;
                }
            }
            // 只记录第一次出现的前缀和 mod k 的结果
            else
            {
                remainder_map[current_sum % k] = i;
            }
        }
        return false;
    }
};