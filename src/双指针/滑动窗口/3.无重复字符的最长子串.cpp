#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.empty())
        {
            return 0; // 如果字符串为空，返回0
        }
        int max_length = 0;
        unordered_map<char, int> word_count;
        for (int i = 0; i < s.length(); i++)
        {
            for (int j = i ; j < s.length(); j++)
            {
                
                /* code */
                auto it = word_count.find(s[j]);
                if (it != word_count.end())
                {
                    // 说明已经记录了该字符，开始下一个字符串的判断
                    word_count.clear();
                    break;
                }
                else
                {
                    // 说明没有记录该字符，记录该字符
                    word_count[s[j]] = 1;
                    // 更新最大长度
                    if (static_cast<int>(word_count.size()) > max_length)
                    {
                        max_length = word_count.size();
                    }
                }
            }
        }
        return max_length;
    }
};


//滑动窗口
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        // 1. 初始化
        unordered_map<char, int> window; // 记录窗口内各字符出现的次数
        int left = 0;                    // 左指针
        int right = 0;                   // 右指针
        int maxLength = 0;               // 记录结果

        // 2. 循环：right指针负责扩大窗口
        while (right < s.length())
        {
            char char_in = s[right];
            right++;
            // 扩大时更新数据
            window[char_in]++;

            // 3. 判断：左侧窗口是否需要收缩
            // 当窗口中某个字符的数量大于1时，说明出现了重复，需要收缩
            while (window[char_in] > 1)
            {
                char char_out = s[left];
                left++;
                // 收缩时更新数据
                window[char_out]--;
            }

            // 4. 更新结果
            // 在[left, right)这个窗口中，没有重复元素
            // 我们在每次扩大窗口后，都来更新一下最大长度
            maxLength = max(maxLength, right - left);
        }

        return maxLength;
    }
};