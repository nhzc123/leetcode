/**
 * @file Subsets2.cpp
 * @brief
 * @author charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-08-30
 */

class Solution {
public:
    vector<vector<int> > result;

    void dfs(int dep, int len, vector<int> tmp, vector<int> &S){
        if (dep == len){
            if (find(result.begin(), result.end(), tmp) == result.end()){
                result.push_back(tmp);
            }
            return ;
        }

        dfs(dep + 1, len, tmp, S);
        tmp.push_back(S[dep]);
        dfs(dep + 1, len, tmp, S);
    }
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        if (S.size() == 0){
            return result;
        }
        vector<int> tmp ;
        sort(S.begin(), S.end());
        dfs(0, S.size(), tmp, S);

        return result;
    }
};
