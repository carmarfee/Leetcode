#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int start = 0, maxLength = 1;
        for (int i = 0; i < s.length() - 1; i++)
        {
            int left = i, right = i;
            // 处理奇数长度的回文
            while (left >= 0 && right < s.length() && s[left] == s[right])
            {
                left--;
                right++;
            }
            maxLength = max(maxLength, right - left - 1);
            // 处理偶数长度的回文
            int evenLeft = i, evenRight = i + 1;
            while (evenLeft >= 0 && evenRight < s.length() && s[evenLeft] == s[evenRight])
            {
                evenLeft--;
                evenRight++;
            }
            maxLength = max(maxLength, evenRight - evenLeft - 1);
            if (maxLength == right - left - 1 || maxLength == evenRight - evenLeft - 1)
            {
                // 更新起始位置
                if (maxLength % 2 == 0)
                {
                    start = i - (maxLength / 2) + 1;
                }
                else
                {
                    start = i - (maxLength / 2);
                }
            }
        }
        return s.substr(start, maxLength);
    }
};