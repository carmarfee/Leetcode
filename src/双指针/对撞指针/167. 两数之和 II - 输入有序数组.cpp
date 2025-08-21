#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

//针对于由于数组，可以考虑对撞指针
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum == target) {
                return {left + 1, right + 1}; // 返回1-based索引
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
        return {}; // 如果没有找到，返回空数组
    }
};



//和两数之和一样的可以使用哈希表
class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        unordered_map<int, int> hashtable;
        for (int i = 0; i < numbers.size(); ++i)
        {
            auto it = hashtable.find(target - numbers[i]);
            if (it != hashtable.end())
            {
                return {it->second + 1, i + 1};
            }
            hashtable[numbers[i]] = i;
        }
        return {};
    }
};