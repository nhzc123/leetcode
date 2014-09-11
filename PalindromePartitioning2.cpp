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
