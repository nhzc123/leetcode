class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if (s == NULL || p == NULL){
            return false;
        }
        if (*p == '\0'){
            return *s == '\0';
        }

        if (*(p + 1) != '*'){
            if (*p == *s || (*s != '\0' && *p == '.')){
                return isMatch(s + 1, p + 1);
            }
            else{
                return false;
            }
        }
        else{
            while ((*s != '\0' && *p == '.') || *p == *s){
                if (isMatch(s,p + 2)){
                    return true;
                }
                s++;
            }
            return isMatch(s,p + 2);
        }
    }
};



DP:
class Solution {
	public:
    bool isMatch(const char *s, const char *p) {
	    int slen = strlen(s), plen = strlen(p), i, j;
	    bool dp[500][500];
	    memset(dp,false, sizeof(dp));
	    dp[0][0] = true;
	    for (i = 1; i <= plen; ++i) {
		        if (p[i] == '*') {
				            dp[i][0] = dp[i + 1][0] = dp[i - 1][0]; //就是说上一个Regular已经与string 匹配 那么+1之后的Regular也和string匹配
				            for (j = 1; j <= slen; ++j)
				                dp[i][j] = dp[i + 1][j] = (dp[i][j - 1] && (p[i - 1] == s[j - 1] || p[i - 1] == '.') || dp[i - 1][j]); //同上
				            ++i;
				        }
		        else
		            for (j = 1; j <= slen; ++j)
		                dp[i][j] = dp[i - 1][j - 1] && (p[i - 1] == s[j - 1] || p[i - 1] == '.');
		    }
	    return dp[plen][slen];
	}
};
