#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        if (s.empty() || t.empty() || s.size() < t.size())
        {
            return "";
        }

        // need 表记录 t 中需要的字符和数量
        unordered_map<char, int> need;
        for (char c : t)
        {
            need[c]++;
        }

        // window 表记录当前窗口中相应字符的数量
        unordered_map<char, int> window;
        int left = 0, right = 0;

        // valid 变量表示窗口中满足 need 条件的字符个数
        // 如果 window[c] >= need[c]，则 c 这个字符是达标的
        int valid = 0;

        // 记录最小覆盖串的起始索引及长度
        int start = 0, len = INT_MAX;

        while (right < s.size())
        {
            // c 是将移入窗口的字符
            char c = s[right];
            // 右移窗口
            right++;
            // 进行窗口内数据的一系列更新
            if (need.count(c))
            { // 如果 c 是 t 中需要的字符
                window[c]++;
                if (window[c] == need[c])
                {
                    valid++; // 当 c 的数量满足需要时，valid+1
                }
            }

            // 判断左侧窗口是否要收缩
            while (valid == need.size())
            {
                // 在这里更新最小覆盖串
                if (right - left < len)
                {
                    start = left;
                    len = right - left;
                }

                // d 是将移出窗口的字符
                char d = s[left];
                // 左移窗口
                left++;
                // 进行窗口内数据的一系列更新
                if (need.count(d))
                { // 如果 d 是 t 中需要的字符
                    if (window[d] == need[d])
                    {
                        valid--; // 当 d 的数量不再满足需要时，valid-1
                    }
                    window[d]--;
                }
            }
        }

        // 返回最小覆盖串，如果 len 还是初始值说明没有找到
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};