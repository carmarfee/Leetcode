#include <vector>
#include <algorithm> // 用于 std::min

class Solution {
public:
    long long minArraySum(std::vector<int>& nums, int k) {
        // 使用一个大小为 k 的向量来模拟哈希表，存储 {余数: 最小dp值}
        // remainder_map[rem] 表示所有前缀和余数为 rem 的位置中，最小的数组和是多少
        std::vector<long long> remainder_map(k);

        // 定义一个足够大的数代表无穷大
        // 注意：不要使用 LLONG_MAX，因为它加上一个正数后会溢出
        const long long INF = 1e18; 
        for (int i = 1; i < k; ++i) {
            remainder_map[i] = INF;
        }
        
        // 初始条件：长度为0的前缀（在数组开始前），其和为0，余数也为0。
        // 这是算法的基石，它允许我们删除一个从数组开头开始的子数组。
        remainder_map[0] = 0;

        long long prefix_sum = 0;
        // dp_val 代表处理到当前元素为止，所能得到的最小和。
        // 初始值为0，代表一个空数组的和。
        long long dp_val = 0; 

        for (int num : nums) {
            prefix_sum += num;
            
            // C++的 '%' 运算符对于负数的结果可能为负，此操作确保余数总是在 [0, k-1] 范围内
            int remainder = (prefix_sum % k + k) % k;

            // 查找与当前前缀和有相同余数的、之前的状态所对应的最小和
            long long min_prev_sum_for_rem = remainder_map[remainder];

            // 计算包含当前元素 num 时的最小和，有两个选择：
            
            // 选择1 (保留 num): 将 num 加到上一步的最小和上
            long long keep_num_sum = dp_val + num;
            
            // 选择2 (删除以 num 结尾的某个子数组):
            // 此时的和等于之前某个状态的最小和，这个状态的前缀和余数与当前相同。
            // 我们已经通过 remainder_map 找到了这个最优值。
            long long delete_subarray_sum = min_prev_sum_for_rem;
            
            // 当前状态的最小和是这两种选择中较小的一个
            long long new_dp_val = std::min(keep_num_sum, delete_subarray_sum);
            
            // 我们得到了一个新的对应 remainder 的最小和，更新 map
            remainder_map[remainder] = std::min(remainder_map[remainder], new_dp_val);

            // 将当前状态的最小和传递给下一次迭代
            dp_val = new_dp_val;
        }
        
        return dp_val;
    }
};


