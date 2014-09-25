/**
 * @file GenerateParentheses.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-09-16
 */

class Solution {
public:
    void dfs(vector<string> &result, int left, int right, int n, string s){
        if (left == n){
            result.push_back(s.append(n - right,')'));
            return ;
        }
        dfs(result, left + 1, right, n, s + '(');
        if (left > right){
            dfs(result, left, right + 1, n, s + ')');
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if (n == 0){
            return result;
        }
        string s = "";
        dfs(result, 0, 0, n, s);
        return result;
    }
};
