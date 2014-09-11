/**
 * @file DecodeWays.cpp
 * @brief
 * @author charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-09-02
 */

class Solution {
public:
    int numDecodings(string s) {
        //简单dp[i] = d[i - 1] if s[i - 1]s[i] > 26 否则 dp[i] = dp[i - 1] + dp[i - 2]
        if (s.length() == 0 || s[0] == '0'){
            return 0;
        }

        if (s.length() == 1){
            return 1;
        }

        int num = 0;
        num = (s[0] -'0') * 10 + s[1] - '0';
        int dp[10000];
        dp[0] = 1;

        if (s[0] > '2' && s[1] == '0'){
            return 0;
        }

        if (num < 27){
            if (num == 10 || num == 20){
                dp[1] = 1;
            }
            else{
                dp[1] = 2;
            }

            if (s.length() == 2)
                return dp[1];
        }
        else{
            dp[1] = 1;

            if (s.length() == 2)
                return 1;
        }


        for (int i = 2; i < s.length(); i ++){
            if (s[i] == '0'){
                if (s[i - 1] == '0' || s[i - 1] > '2'){
                    return 0;
                }
                else{
                    dp[i] = dp[i - 2];
                }
            }
            else{
                if (s[i - 1] == '1' ||(s[i - 1] == '2' && s[i] <= '6')){
                    dp[i] = dp[i - 1] + dp[i - 2];
                }
                else{
                    dp[i] = dp[i - 1];
                }
            }
        }

        return dp[s.length() - 1];
    }
};
