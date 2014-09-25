/**
 * @file ScrambleString.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-09-14
 */
class Solution {
public:
    //递归 + 剪枝做法
    //主要是遍历所有切换的位置，比如找到一个位置 i , 那么第一个字符串分为左1，左2，第二个字符串分为右1, 右2,则返回true的规则为
    //isScamble(左1，右1) && isScamble(左2，右2)|| isScamble(左1,右2) &&isScamble(左2，右1)
    bool isScramble(string s1, string s2) {
        if (s1.length() != s2.length()){
            return false;
        }
        if (s1 == s2){
            return true;
        }
        int alpha[26] = {0};//计算s1, 跟s2是否有相同的字母数
        for (int i = 0; i < s1.length(); i ++){
            alpha[s1[i] - 'a'] ++;
        }
        for (int i = 0; i < s2.length(); i ++){
            alpha[s2[i] - 'a'] --;
        }
        //如果字母不对应  剪枝
        for (int i = 0; i < 26; i ++){
            if (alpha[i] != 0){
                return false;
            }
        }
        //遍历所有分割的位置
        for (int i = 1; i < s1.length(); i ++){
            if ((isScramble(s1.substr(0,i), s2.substr(0,i)) && isScramble(s1.substr(i), s2.substr(i))) || (isScramble(s1.substr(0,i), s2.substr(s2.length()-i, i)) && isScramble(s1.substr(i), s2.substr(0,s2.length()-i)))){
                return true;
            }
        }
        return false;
    }
};


class Solution {
public:
    //动态规划做法 F[i][j][k] 记录位置为i，j开始的字符串总长度为k是否为scramble，
    //当k = 1的时候，s[i] == s[j] 的话则f[i][j][k]为true
    //大循环遍历字符串长度为k的时候的情况，小循环l,遍历在此字符串长度下以l为分隔位置的字符串是否为scramble
    //那么可以得到公式f[i][j][k] = (f[i][j][l] && f[i + l][j + l][k - l]) || (f[i][j + k - l][l] && f[i + l][j][k - l])
    //主要是遍历所有切换的位置，比如找到一个位置 i , 那么第一个字符串分为左1，左2，第二个字符串分为右1, 右2,则返回true的规则为
    //isScamble(左1，右1) && isScamble(左2，右2)|| isScamble(左1,右2) &&isScamble(左2，右1)
    bool isScramble(string s1, string s2) {
        if (s1.length() != s2.length()){
            return false;
        }
        if (s1 == s2){
            return true;
        }
        bool dp[s1.length()][s2.length()][s1.length()];
        memset(dp, false, sizeof(bool) * s1.length() * s2.length() * s1.length());
        //从字符串长度为1开始遍历
        for (int k = 1; k <= s1.length(); k ++){
            //遍历s1的起始位置
            for (int i = 0; i <= s1.length() - k; i ++){
                //遍历s2的起始位置
                for (int j = 0; j <= s1.length() - k; j ++){
                    if (k == 1){
                        dp[i][j][k] = (s1[i] == s2[j]);
                    }
                    //对于k长度的字符串，遍历它的分隔位置
                    for (int l = 1; l < k; l ++){
                        dp[i][j][k] = (dp[i][j][l] && dp[i + l][j + l][k - l]) || (dp[i][j + k - l][l] && dp[i + l][j][k - l]);
                        if (dp[i][j][k]){
                            break;
                        }
                    }
                }
            }
        }
        return dp[0][0][s1.length()];
    }
};
