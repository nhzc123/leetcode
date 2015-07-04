公式的含义是，从i开始的字符串的最小划分为：如果从位置i到位置j的子串是回文串，则从i开始的划分可以通过将i到j的子串看作划分的一部分，然后加上从j+1位置开始的子串最小划分，并选择可能情况中的最小值即为从i开始的最小划分。
class Solution {
public:

    const static int MAXNUM = 2000;
    bool dp[MAXNUM][MAXNUM];
    int cut[MAXNUM];

    int minCut(string s) {

        memset(dp,0,sizeof(dp));
        memset(cut,0,sizeof(cut));

        for (int i = 0; i < s.length(); i ++){
            dp[i][i] = true;
        }

        for (int i = 0;i < s.length();i ++){
            int l = i - 1;
            int r = i;

            while (l >= 0 && r < s.length() && s[l] == s[r]){
                dp[l--][r++] = true;
            }

            l = i - 1;
            r = i + 1;

            while (l >= 0 && r < s.length() && s[l] == s[r]){
                dp[l--][r++] = true;
            }

        }

        cut[s.length()] = 0;

        for (int i = s.length() - 1;i >= 0; i--){

            cut[i] = s.length() - i;

            for (int j = i; j < s.length();j++){
                if(dp[i][j]){

                    cut[i] = cut[i] < (1 + cut[j + 1]) ? cut[i]:(1 + cut[j + 1]);
                }
            }
        }

        return cut[0] - 1;

    }
};
