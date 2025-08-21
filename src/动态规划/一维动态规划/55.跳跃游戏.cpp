#include <vector>
#include <iostream>
using namespace std;


//distance表示前i个元素能跳到的最远距离
//如果发现最远距离小于i，说明无法到达i位置
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int distance = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (distance < i)
                return false;
            distance = max(i + nums[i], distance);
        }
        return true;
    }
};