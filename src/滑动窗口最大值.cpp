#include <vector>
#include <deque>
using namespace std;
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        if (nums.empty() || k <= 0)
        {
            return {};
        }

        std::vector<int> result;
        // 双端队列，存储的是元素的下标
        std::deque<int> dq;

        for (int i = 0; i < nums.size(); ++i)
        {
            // 1. 移除滑出窗口的旧的最大值
            // 当队首元素的下标 <= i-k 时，表示它已不在当前窗口 [i-k+1, i] 内
            if (!dq.empty() && dq.front() <= i - k)
            {
                dq.pop_front();
            }

            // 2. 维护队列的单调递减性
            // 从队尾开始，移除所有比当前元素 nums[i] 小的元素的下标
            while (!dq.empty() && nums[dq.back()] <= nums[i])
            {
                dq.pop_back();
            }

            // 3. 将当前元素的下标入队
            dq.push_back(i);

            // 4. 记录当前窗口的最大值
            // 当窗口形成后 (i >= k-1)，队首元素就是当前窗口最大值的下标
            if (i >= k - 1)
            {
                result.push_back(nums[dq.front()]);
            }
        }
        return result;
    }
};