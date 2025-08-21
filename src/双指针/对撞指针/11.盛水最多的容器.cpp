#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int right = 0;
        int left = height.size() - 1;
        int max_area = 0;
        int cur_area = 0;
        while (right < left)
        {
            cur_area = std::min(height[right], height[left]) * (left - right);
            max_area = std::max(max_area, cur_area);
            if (height[right] < height[left])
            {
                ++right;
            }
            else
            {
                --left;
            }
        }
        return max_area;
    }
};
/*
这题有以下决策思想

1. 贪心算法
   -遍历起始点确定： 从两边向中间逼近，每次移动较小的一边
   -为什么移动较小的一边？因为面积是由两边的高度和宽度决定的，移动较小的一边可能会找到更大的高度，从而增加面积。
   -为什么不移动较大的边？因为移动较大的边不会增加面积，反而可能减少宽度。
   -为什么不考虑增大宽度？保证向中间逼近。
   -为什么不从中间开始？因为从两边向中间逼近可以保证每次都能找到一个更大的面积。
   -为什么不考虑所有可能的组合？因为暴力破解的时间复杂度是O(n^2)，而贪心算法的时间复杂度是O(n)，更高效（决策剪枝）。
2. 双指针法
*/
