#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        if (matrix.empty() || matrix[0].empty())
        {
            return {};
        }
        int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // 右、下、左、上
        int rows = matrix.size();
        int cols = matrix[0].size();

        int cur_pos[2] = {0, -1};      // 当前坐标
        int cur_dir_index = 0; // 初始方向为右

        vector<int> result;
        while (true)
        {
            for (int i = 0; i < (dir[cur_dir_index][0] == 0 ? cols : rows); i++)
            {
                cur_pos[0] += dir[cur_dir_index][0];
                cur_pos[1] += dir[cur_dir_index][1];
                result.push_back(matrix[cur_pos[0]][cur_pos[1]]);                
            }
            // 更新方向
            cur_dir_index = (cur_dir_index + 1) % 4; // 顺时针转向

            // 更新子矩阵行和宽
            if (dir[cur_dir_index][0] == 0)
            {
                rows--; // 如果方向是水平的，减少行数
            }
            else
            {
                cols--; // 如果方向是垂直的，减少列数
            }
            if (rows <= 0 || cols <= 0)
            {
                break; // 如果行或列数小于等于0，结束循环
            }
        }
        return result; // 返回结果
    }
};

class Solution {
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return {};
        }

        int m = matrix.size();
        int n = matrix[0].size();
        std::vector<int> result;
        result.reserve(m * n); // 提前预留空间，提高效率

        int top = 0, bottom = m - 1;
        int left = 0, right = n - 1;

        while (top <= bottom && left <= right) {
            // 1. 从左到右遍历上边界
            for (int i = left; i <= right; ++i) {
                result.push_back(matrix[top][i]);
            }
            top++;

            // 2. 从上到下遍历右边界
            for (int i = top; i <= bottom; ++i) {
                result.push_back(matrix[i][right]);
            }
            right--;

            // 检查边界是否交叉，防止在单行或单列矩阵中重复遍历
            if (top > bottom || left > right) {
                break;
            }

            // 3. 从右到左遍历下边界
            for (int i = right; i >= left; --i) {
                result.push_back(matrix[bottom][i]);
            }
            bottom--;

            // 4. 从下到上遍历左边界
            for (int i = bottom; i >= top; --i) {
                result.push_back(matrix[i][left]);
            }
            left++;
        }

        return result;
    }
};