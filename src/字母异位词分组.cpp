#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string sortString(string s)
    {
        string sorted_s = s;
        sort(sorted_s.begin(), sorted_s.end()); // 对字符串进行排序
        return sorted_s;
    }
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, int> hashtable; // 哈希表存储已处理的字符串，这个字符串是根据字符串的字符排序后的字符串（ASCII值排序字符串）
        int index = 0;                        // 哈希表的索引
        vector<vector<string>> result;
        for (const string &s : strs)
        {
            // 对每个字符串进行排序
            string sorted_s = sortString(s);
            vector<string> group;
            group.push_back(s);
            if (hashtable.find(sorted_s) == hashtable.end())
            {
                result.push_back(group);
                hashtable[sorted_s] = index;
                index++;
            }
            else
            {
                result[hashtable[sorted_s]].push_back(s);
            }
        }
        return result;
    }
};