#include <vector>
#include <algorithm> // for std::max and std::min

class Solution
{
public:
    std::vector<std::vector<int>> permute(std::vector<int> &nums)
    {
        std::vector<std::vector<int>> result;       // 存储所有排列结果
        std::vector<int> path;                      // 存储当前路径（一个正在构建的排列）
        std::vector<bool> used(nums.size(), false); // 标记数字是否已被使用

        backtrack(nums, result, path, used);

        return result;
    }

private:
    void backtrack(const std::vector<int> &nums,
                   std::vector<std::vector<int>> &result,
                   std::vector<int> &path,
                   std::vector<bool> &used)
    {

        // 3. 结束条件：当路径的长度等于数字总数时，找到了一个完整的排列
        if (path.size() == nums.size())
        {
            result.push_back(path); // 记录结果
            return;
        }

        // 遍历所有可能的选择
        for (int i = 0; i < nums.size(); ++i)
        {
            // 如果这个数字已经被用过了，就跳过
            if (used[i])
            {
                continue;
            }

            // --- 核心的回溯模板 ---
            // 1. 做出选择
            path.push_back(nums[i]);
            used[i] = true;

            // 2. 进入下一层决策
            backtrack(nums, result, path, used);

            // 3. 撤销选择
            used[i] = false; // 将标记重置
            path.pop_back(); // 将路径恢复
        }
    }
};