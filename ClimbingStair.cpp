/**
 * @file ClimbingStair.cpp
 * @brief
 * @author charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-09-02
 */

class Solution {
public:
    int climbStairs(int n) {
        if (n == 0){
            return 0;
        }

        int dp[1000];
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= n; i ++){
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];

    }
};
