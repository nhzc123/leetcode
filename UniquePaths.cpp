/**
 * @file UniquePaths.cpp
 * @brief
 * @author charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-09-04
 */

class Solution {
public:

    int uniquePaths(int m, int n) {
        int dp[101][101];

        memset(dp, 0, sizeof(dp));

        for (int i = 0; i < m; i ++){
            dp[i][0] = 1;
        }
        for (int j = 0; j < n; j ++){
            dp[0][j] = 1;
        }

        for (int i = 1; i < m; i ++){
            for (int j = 1; j < n; j ++){
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m -1][n - 1];
    }
};
