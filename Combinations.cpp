/**
 * @file Combinations.cpp
 * @brief
 * @author charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-09-04
 */
class Solution {
public:
    vector<vector<int> > result;


    void dfs(const int &k, const int &n, int step, vector<int> tmp, int start){
        if (k == step){
            result.push_back(tmp);
            return;
        }

        for (int i = start; i <= n; i ++){

                tmp[step] = i;

                dfs(k, n, step + 1, tmp, i + 1);


            }

    }
    vector<vector<int> > combine(int n, int k) {
        result.clear();
        vector<int> tmp(k);

        dfs (k, n, 0, tmp, 1);

        return result;

    }
};
