#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;


class Solution
{
public:
    bool isPalindrome(string s)
    {
        int left = 0, right = s.size() - 1;
        while (left < right)
        {
            if (!isalnum(s[left]))
            {
                left++;
                continue;
            }
            else if (!isalnum(s[right]))
            {
                right--;
                continue;
            }
            if (tolower(s[left]) != tolower(s[right]))
            {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};

int main()
{
    Solution solution;
    string s = "A man, a plan, a canal: Panama";
    bool result = solution.isPalindrome(s);
    cout << (result ? "true" : "false") << endl;
    
    // 添加测试用例
    string test1 = "race a car";
    bool result1 = solution.isPalindrome(test1);
    cout << (result1 ? "true" : "false") << endl;
    
    string test2 = " ";
    bool result2 = solution.isPalindrome(test2);
    cout << (result2 ? "true" : "false") << endl;
    
    string test3 = "No 'x' in Nixon";
    bool result3 = solution.isPalindrome(test3);
    cout << (result3 ? "true" : "false") << endl;
    
    string test4 = "Was it a car or a cat I saw?";
    bool result4 = solution.isPalindrome(test4);
    cout << (result4 ? "true" : "false") << endl;
    
    return 0;
}