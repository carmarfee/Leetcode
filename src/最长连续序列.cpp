#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution

{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> num_set(nums.begin(), nums.end());
        int max_length = 0;
        int cur_length = 0;
        for (const auto &num : num_set)
        {
            // 首先判断是否是序列起始点
            if (num_set.find(num - 1) == num_set.end())
            {
                // 如果是序列起始点，则开始计算序列长度
                cur_length = 1;
                while (num_set.find(num + cur_length) != num_set.end())
                {
                    cur_length++;
                }
                max_length = max(max_length, cur_length);
            }
        }
        return max_length;
    }
};