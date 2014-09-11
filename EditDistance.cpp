/**
 * @file EditDistance.cpp
 * @brief
 * @author charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-09-01
 */

class Solution {
public:


    int minDistance(string word1, string word2) {
            //动态规划 dp[i][j] 代表了从word[i] 变化到word[j]所需要的最小步骤，当s[i] == s[j] 的时候 dp[i][j] == dp[i - 1][j - 1],当
            //s[i] != s[j] 的时候， dp[i][j] = min(dp[i - 1][j],dp[i][j -1]) + 1

            int len1 = word1.length();
            int len2 = word2.length();
            int **dp = new int *[len1 + 1];

            for (int i = 0; i <= len1; i ++){
                dp[i] = new int [len2 + 1];
            }
            for (int i = 0; i <= len1; i ++){
                for (int j = 0; j <= len2; j ++){
                    dp[i][j] = 0;
                }
            }

            for (int i = 0; i <= len1; i ++){
                dp[i][0] = i;
            }
            for (int j = 0; j <= len2; j ++){
                dp[0][j] = j;
            }
            for (int i = 1; i <= len1; i ++){
                for (int j = 1; j <= len2; j ++){
                    if (word1[i - 1] == word2[j - 1]){
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                    else{
                        dp[i][j] = min(dp[i - 1][j - 1],min(dp[i - 1][j], dp[i][j - 1])) + 1;
                    }
                }
            }

            return dp[len1][len2];
    }
};
