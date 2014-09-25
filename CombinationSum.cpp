/**
 * @file CombinationSum.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-09-24
 */

class Solution {
public:
    void dfs (vector<int> &candidates, vector<int> &cur, vector<vector<int> > &result, int start, int target){
        if (target == 0){
            result.push_back(cur);
        }
        else{
            for (int i = start; i < candidates.size(); i ++){
                if (candidates[i] > target){
                    continue;
                }
                cur.push_back(candidates[i]);
                dfs(candidates, cur, result, i, target - candidates[i]);
                cur.pop_back();
            }
        }
    }
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > result;
        if (candidates.size() == 0){
            return result;
        }
        sort(candidates.begin(), candidates.end());
        vector<int> cur;
        dfs(candidates, cur, result, 0, target);
        return result;
    }
};
