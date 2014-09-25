class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        //递归解法
        //设定返回条件
        //如果P[j+1]!='*'，S[i] == P[j]=>匹配下一位(i+1, j+1)，S[i]!=P[j]=>匹配失败；
        //如果P[j+1]=='*'，S[i]==P[j]=>匹配下一位(i+1, j+2)或者(i, j+2)，S[i]!=P[j]=>匹配下一位(i,j+2)。
        //匹配成功的条件为S[i]=='\0' && P[j]=='\0'。

        if (s == NULL || p == NULL){
            return false;
        }
        if (*p == '\0'){ //要同时到达最后面
            return *s == '\0';
        }
        if (*(p + 1) == '*'){
            //需要循环判断s中出现的各种情况
            while (*s == *p || (*s != '\0' &&*p == '.')){
                if (isMatch(s, p + 2)){
                    return true;
                }
                s ++;
            }
            return isMatch(s, p + 2);
        }
        else{
            if (*s == *p || (*s != '\0' &&*p == '.')){
                return isMatch(s + 1, p + 1);
            }
            else{
                return false;
            }
        }

}
};


DP:

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        //再次尝试DP解法
        bool dp[500][500];
        int lenS = strlen(s);
        int lenP = strlen(p);
        memset(dp, false, sizeof(dp));
        dp[0][0] = true;//初始化
        for (int i = 1; i <= lenP; i ++){
            if (p[i] == '*'){
                dp[i][0] = dp[i + 1][0] = dp[i - 1][0];//因为*号匹配前面字母的任意情况
                for (int j = 1; j <= lenS; j ++){
                    dp[i][j] = dp[i + 1][j] = (dp[i][j - 1] && (p[i - 1] == s[j - 1] || p[i - 1] == '.')) || dp[i - 1][j];
                    //此时能否为regular取决于
                    //dp[i][j - 1] p[i - 1]与s[j - 2]位置已经是相同的，并且p[i - 1]与s[j - 1]的位置也是相同的或者p[i - 1]为.可以
                    //匹配任意的字符串
                    //或者dp[i - 1][j]已经匹配那么 p中的.*可以不取任意一个数
                }
                i ++;//跳过检查*为前缀的那个步骤
            }
            else{
                for (int j = 1; j <= lenS; j ++){
                    dp[i][j] = dp[i - 1][j - 1] && (p[i - 1] == s[j - 1] || p[i - 1] == '.');
                }
            }
        }
        return dp[lenP][lenS];

}
};
