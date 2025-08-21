class Solution {
public:
    int minDistance(std::string word1, std::string word2) {
        int m = word1.length();
        int n = word2.length();

        // dp[i][j]: word1的前i个字符 -> word2的前j个字符 的最少操作数
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

        // --- 步骤3：初始化 ---
        // 初始化第一列：word1 -> "" (需要 i 次删除)
        for (int i = 0; i <= m; ++i) {
            dp[i][0] = i;
        }
        // 初始化第一行："" -> word2 (需要 j 次插入)
        for (int j = 0; j <= n; ++j) {
            dp[0][j] = j;
        }

        // --- 步骤2：状态转移 ---
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                // 注意 C++ string 索引从0开始，所以用 i-1, j-1
                if (word1[i - 1] == word2[j - 1]) {
                    // 情况一：字符相同，无需操作
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    // 情况二：字符不同，取三种操作的最小值 + 1
                    dp[i][j] = 1 + std::min({
                        dp[i - 1][j - 1], // 替换
                        dp[i - 1][j],     // 删除
                        dp[i][j - 1]      // 插入
                    });
                }
            }
        }

        return dp[m][n];
    }
};