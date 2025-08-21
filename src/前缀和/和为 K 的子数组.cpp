#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution
{
public:
    int subarraySum(std::vector<int>& nums, int k) {
        // 哈希表，存储 {前缀和 -> 该前缀和出现的次数}
        std::unordered_map<int, int> prefix_sum_map;
        
        // 关键初始化：前缀和为0的出现次数为1。
        // 这处理了从数组开头就和为k的子数组情况。
        prefix_sum_map[0] = 1; 
        
        int count = 0;
        int current_sum = 0;
        
        // 遍历数组
        for (int num : nums) {
            // 1. 更新当前的前缀和
            current_sum += num;
            
            // 2. 计算需要寻找的目标前缀和
            int target = current_sum - k;
            
            // 3. 在哈希表中查找目标
            // 如果找到了，说明存在一个或多个从开头到某个位置的前缀和为 target，
            // 那么从那个位置之后到当前位置的子数组和就是 k。
            if (prefix_sum_map.count(target)) {
                count += prefix_sum_map[target];
            }
            
            // 4. 将当前的前缀和存入哈希表，更新其出现次数
            prefix_sum_map[current_sum]++;
        }
        
        return count;
    }
};