class Solution
{
public:
    int climbStairs(int n)
    {
        if (n <= 2)
        {
            return n;
        }

        // 初始化前两个台阶的方式数
        int first = 1; // 第一个台阶
        int second = 2; // 第二个台阶
        int current;

        // 从第三个台阶开始计算
        for (int i = 3; i <= n; ++i)
        {
            current = first + second; // 当前台阶的方式数等于前两个台阶的方式数之和
            first = second; // 更新前一个台阶
            second = current; // 更新当前台阶
        }

        return current; // 返回第 n 个台阶的方式数
    }
};