/**
 * @file InterleavingString.cpp
 * @brief
 * @author charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-09-01
 */

class Solution {
public:
    bool flag[1000][1000];
    bool isInterleave(string s1, string s2, string s3) {
        //dp解决，f[i][j] 保存数组s1[0,i] s2[0,j] 和s3[0,i + j]的匹配情况
        /*设状态 f[i][j],表示 s1[0,i] 和 s2[0,j],匹配 s3[0, i+j]。如果 s1 的最后一个字符等 于 s3 的最后一个字符,则 f[i][j]=f[i-1][j];如果 s2 的最后一个字符等于 s3 的最后一个字符, 则 f[i][j]=f[i][j-1]。因此状态转移方程如下:
  f[i][j] = (s1[i - 1] == s3 [i + j - 1] && f[i - 1][j])
         || (s2[j - 1] == s3 [i + j - 1] && f[i][j - 1]);
        */
        if (s1.length() + s2.length() != s3.length()){
            return false;
        }

        memset(flag,false,sizeof(flag));

        //空字符串
        flag[0][0] = true;

        for (int i = 1; i <= s1.length(); i ++){
            flag[i][0] = flag[i - 1][0] && (s1[i - 1] == s3[i - 1]);
        }

        for (int j = 1; j <= s2.length(); j ++){
            flag[0][j] = flag[0][j - 1] && (s2[j - 1] == s3[j - 1]);
        }

        for (int i = 1; i <= s1.length(); i ++){
            for (int j = 1; j <= s2.length(); j ++){
                flag[i][j] = (s2[j - 1] == s3[i + j - 1] && flag[i][j - 1])||(s1[i - 1] == s3[i + j - 1] && flag[i - 1][j]);
            }
        }

        return flag[s1.length()][s2.length()];

    }
};
