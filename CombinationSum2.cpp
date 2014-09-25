/**
 * @file CombinationSum2.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-09-24
 */

class Solution {
public:
    void dfs(vector<int> &num, vector<vector<int> > &result, vector<int> &cur, int target, int step){
        if (step > num.size()){
            return ;
        }
        if (target == 0){
            if (find(result.begin(), result.end(), cur) == result.end()){
                result.push_back(cur);
            }
        }
        else{
            dfs(num, result, cur, target, step + 1);
            if (target >= num[step]){
                cur.push_back(num[step]);
                dfs(num, result, cur, target - num[step], step + 1);
                cur.pop_back();
            }
        }
    }
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int> > result;
        if (num.size() == 0){
            return result;
        }
        sort(num.begin(), num.end());
        vector<int> cur;
        dfs(num, result, cur, target, 0);
        return result;
    }
};
