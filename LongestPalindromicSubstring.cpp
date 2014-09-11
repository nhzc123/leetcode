/**
 * @file LongestPalindromicSubstring.cpp
 * @brief
 * @author charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-08-31
 */
class Solution {
public:
    bool flag[1000][1000];
    //dp算法
    string longestPalindrome(string s) {
        memset(flag,false,sizeof(flag));
        int n = s.length();
        int startSub = 0;
        int maxLen = 0;

        if (n == 0){
            return "";
        }
        //初始情况，每一个单数都是true
        for (int i = 0; i < n; i ++){
            flag[i][i] = true;
            startSub = i;
            maxLen = 1;
        }
        //初始情况，相邻两个相同的话是true
        for (int i = 0; i < n - 1; i ++){
            if (s[i] == s[i + 1]){
                flag[i][i + 1] = true;
                startSub = i;
                maxLen = 2;
            }
        }

        //假设回文子串长度从3开始算起
        for (int len = 3; len <= n; len ++){
            for (int i = 0; i < n - len + 1; i ++){
                int j = i + len - 1;

                if (s[i] == s[j] && flag[i + 1][j - 1]){
                    flag[i][j] = true;
                    startSub = i;
                    maxLen = len;
                }
            }
        }

        return s.substr(startSub,maxLen);

    }
};
