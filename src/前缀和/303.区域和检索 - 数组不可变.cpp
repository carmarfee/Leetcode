#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

class NumArray
{
private:
    vector<int> prefix_sum_;

public:
    NumArray(vector<int> &nums)
    {
        prefix_sum_.resize(nums.size() + 1, 0);
        for (int i = 1; i <= nums.size(); i++)
        {
            prefix_sum_[i] = prefix_sum_[i - 1] + nums[i - 1];
        }
    }

    int sumRange(int left, int right)
    {
        return prefix_sum_[right + 1] - prefix_sum_[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */