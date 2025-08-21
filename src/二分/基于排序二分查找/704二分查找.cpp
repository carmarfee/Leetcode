#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int mid = (nums.size() - 1 )/ 2;
        while(1){
            if(nums[mid] == target){
                return mid; // 找到目标值，返回索引
            }else if(nums[mid] > target){
                // 目标值在左半部分
                if(mid == 0){
                    return -1; // 如果 mid 已经是第一个元素，说明目标值不在数组中
                }
                mid = mid / 2; // 更新 mid 为左半部分的中间索引
            }else{
                // 目标值在右半部分
                if(mid == nums.size() - 1){
                    return -1; // 如果 mid 已经是最后一个元素，说明目标值不在数组中
                }
                mid = (mid + nums.size() - 1) / 2; // 更新 mid 为右半部分的中间索引
            }
        }
        return -1; // 如果循环结束仍未找到目标值，返回 -1
    }
};