/**
 * @file Subsets.cpp
 * @brief
 * @author charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-08-30
 */

class Solution {
public:
    vector<vector<int> > result;

    void dfs(int dep, int len, vector<int> tem, vector<int> &S){
        if (dep == len){
            result.push_back(tem);
            return ;
        }
        dfs(dep + 1, len, tem, S);//不加
        tem.push_back(S[dep]);
        dfs(dep + 1, len, tem, S);
    }
    vector<vector<int> > subsets(vector<int> &S) {
        if (S.size() == 0 ){
            result.push_back(S);
            return result;
        }

        vector<int> tem;

        sort(S.begin(),S.end());

        dfs(0, S.size(), tem, S);

        return result;




    }
};
