/**
 * @file ShortestPalindrome.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2015-06-01
 */
class Solution {
public:
//使用kmp算法 将s字符串reverse一下 然后接上# 再接上res_s
//变成了一个s#res_s字符串
//使用kmp算出最后一个字符串的Next数组是多少 比如 aacecaaa#aaacecaa的最后一个a的next数组为7 说明在新字符串中
// 最后一个a的前缀aacecaa和开头的a后缀aacecaa是相同的 这时候只要不上res_s的length - next[lenght-1]的字符就是所求
    string shortestPalindrome(string s) {
        string r = s;
        reverse(r.begin(), r.end());
        string t = s + "#" + r;
        vector<int> p(t.size() + 1, 0);
        /*for (int i = 1; i < t.size(); ++i) {
            int j = p[i - 1];
            while (j > 0 && t[i] != t[j]) j = p[j - 1];
            p[i] = (j += t[i] == t[j]);
        }
        */
        p[0] = -1;
        int i = 0, j = -1;
        while (i < t.size()){
            if (j == - 1 || t[i] == t[j]){
                i ++;
                j ++;
                p[i] = j;

            }
            else{
                j = p[j];
            }
        }
        return r.substr(0, s.size() - p[t.size() ]) + s;
    }
};
