#include <vector>
using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int slow = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                // 每次保证是0和非0的交换
                swap(nums[slow++], nums[i]);
            }
        }
    }
};