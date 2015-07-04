/**
 * @file CombinationSum3.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2015-06-01
 */
class Solution {
public:
    void dfs(int pos, int k, int n, vector<int> tem, vector<vector<int> > &result){
        if (k == 0){
            if (n == 0){
                result.push_back(tem);
            }
            return ;
        }
        vector<int> v;
        for (int i = pos; i <= 9; i ++){
            if (n - i < 0){
                return ;
            }
            v = tem;
            v.push_back(i);
            dfs(i + 1, k - 1, n - i, v, result);
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int> > result;
        vector<int> tem;
        if (n < 1 || k == 0){
            return result;
        }
        dfs(1, k, n, tem, result);
        return result;
    }
};
