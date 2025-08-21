#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return {};
        }
        // 步骤1：对区间按照起始时间进行排序
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        // 步骤2：初始化第一个区间
        vector<int> currentInterval = intervals[0];
        // 步骤3：遍历所有区间
        for (int i = 1; i < intervals.size(); ++i) {
            // 如果当前区间的起始时间小于等于上一个区间的结束时间，说明有重叠
            if (intervals[i][0] <= currentInterval[1]) {
                // 合并区间
                currentInterval[1] = max(currentInterval[1], intervals[i][1]);
            } else {
                // 没有重叠，将当前区间添加到结果中
                merged.push_back(currentInterval);
                currentInterval = intervals[i]; // 更新当前区间为新的区间
            }
        }
        merged.push_back(currentInterval);
        return merged; // 添加最后一个区间到结果中
    }
};