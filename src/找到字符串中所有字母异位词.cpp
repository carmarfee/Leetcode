#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        unordered_map<char, int> p_hashtable;
        vector<int> result;
        if (p.size() > s.size())
        {
            return result; // 如果p的长度大于s，直接返回空结果
        }
        for (int i = 0; i < p.size(); i++)
        {
            p_hashtable[p[i]]++;
        }
        for (int i = 0; i < s.size() - p.size() + 1; i++)
        {
            unordered_map<char, int> s_hashtable;
            for (int j = i; j < i + p.size(); j++)
            {
                s_hashtable[s[j]]++;
            }
            if (s_hashtable == p_hashtable)
            {
                result.push_back(i);
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    string s = "aaaaaaaaaa";
    string p = "aaaaaaaaaaaaa";
    vector<int> result = solution.findAnagrams(s, p);
    for (int i : result)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}