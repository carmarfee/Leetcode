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
