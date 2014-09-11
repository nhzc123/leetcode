/**
 * @file DistinctSubsequences.cpp
 * @brief
 * @author charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-08-31
 */
class Solution {
public:
    //int **dp;
//字符串匹配，一般都是动态规划
//该题目的意思是从S中有多少种删除字符串的方法变成T
    int numDistinct(string S, string T) {

       int lenS = S.length();
        int lenT = T.length();

        if (lenS < lenT){
            return 0;
        }


       int **dp = new int *[S.size() + 1];

       for (int i = 0; i <= S.size(); i ++){
           dp[i] = new int [T.size() + 1];
       }

        //初始化 将任意字符串变成""都只有一个方法
        for (int i = 0; i <= lenS; i ++){
            dp[i][0] = 1;
        }

        for (int j = 0; j <= lenT; j ++){
            dp[0][j] = 0;
        }
        //从空字符串变成空字符串
        dp[0][0] = 1;

        for (int i = 1; i <= lenS; i ++){
            for (int j = 1; j<= lenT; j ++){
                //如果s[i] == t[j] 那么dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]
                //意思是说如果当前位置相同，那么可以选择加上s[i]这个字母dp[i - 1][j - 1]或者加上之前i - 1就已经跟j匹配好的总数dp[ i - 1][j]
                if (S[i - 1] == T[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                }
                //否则 当前长度只能依靠之前的数目
                else{
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[lenS][lenT];
    }
};
