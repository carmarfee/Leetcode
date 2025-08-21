#include <vector>
#include <algorithm> // for std::max and std::min
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<long> pre_product; // 前缀积
        vector<long> suf_product; // 后缀积
        int n = nums.size();
        vector<int> result(n, 1); // 初始化结果数组
        pre_product.resize(n+1);
        suf_product.resize(n+1);
        pre_product[0] = 1; // 前缀积的初始值
        suf_product[n] = 1; // 后缀积的初始值
        // 计算前缀积
        for (int i = 1; i <= n; i++) {
            pre_product[i] = pre_product[i - 1] * nums[i - 1];
        }
        // 计算后缀积
        for (int i = n - 1; i >= 0; i--) {
            suf_product[i] = suf_product[i + 1] * nums[i];
        }
        for (int i = 0; i < n; i++)
        {
            result[i] = pre_product[i] * suf_product[i + 1]; // 计算结果
        }
        return result;
    }
};


//进阶，算后缀积的同时计算结果
class Solution
{
public:
    std::vector<int> productExceptSelf(std::vector<int> &nums)
    {
        int n = nums.size();
        std::vector<int> answer(n);

        // --- 第一遍遍历：计算前缀积 ---
        // answer[i] 先用来存储 nums[i] 左侧的乘积
        int prefix_prod = 1;
        for (int i = 0; i < n; ++i)
        {
            answer[i] = prefix_prod;
            prefix_prod *= nums[i];
        }

        // --- 第二遍遍历：计算后缀积并乘以之前的前缀积 ---
        int suffix_prod = 1;
        for (int i = n - 1; i >= 0; --i)
        {
            // answer[i] 已经存好了左侧乘积，现在再乘上右侧乘积
            answer[i] *= suffix_prod;
            // 更新后缀积，为下一个元素（左边的元素）做准备
            suffix_prod *= nums[i];
        }

        return answer;
    }
};