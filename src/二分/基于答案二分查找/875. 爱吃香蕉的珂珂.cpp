#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool canEat(std::vector<int> &piles, int speed, int h)
    {
        long long totalHours = 0;
        for (int pile : piles)
        {
            totalHours += (pile + speed - 1) / speed; // 向上取整
        }
        return totalHours <= h;
    }
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int left = 1; // 最小速度
        int right = *max_element(piles.begin(), piles.end()); // 最大速度
        while (left < right)
        {
            int mid = left + (right - left) / 2; // 中间速度
            if (canEat(piles, mid, h))
            {
                right = mid; // 如果可以在 h 小时内吃完，尝试更小的速度
            }
            else
            {
                left = mid + 1; // 否则增加速度
            }
        }
        return left; // 返回最小速度

    }
};