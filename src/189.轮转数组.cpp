#include <vector>
#include <algorithm>
using namespace std;

/*
初始状态：[A, B] (A是前 n-k 个元素，B是后 k 个元素)

目标状态：[B, A]

第1步 (整体反转)： [A, B] -> [B_rev, A_rev] (B和A的位置换了，但内部都反了)

第2步 (反转前k个)： [B_rev, A_rev] -> [B, A_rev] (把B内部的顺序正过来)

第3步 (反转后n-k个)： [B, A_rev] -> [B, A] (把A内部的顺序正过来)
*/
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        k = k % n; // 处理 k 大于数组长度的情况
        if (k == 0 || n <= 1) // 如果 k 为0或数组长度小于等于1，则不需要旋转
        {
            return;
        }

        // 反转整个数组
        reverse(nums.begin(), nums.end());
        // 反转前 k 个元素
        reverse(nums.begin(), nums.begin() + k);
        // 反转后 n-k 个元素
        reverse(nums.begin() + k, nums.end());
        
    }
};