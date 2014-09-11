/**
 * @file Permutation.cpp
 * @brief
 * @author charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-08-30
 */

class Solution {
public:
vector<vector<int> > result;

void dfs(vector<int> num,vector<int> tem){
    if (num.size() == 0){
        result.push_back(tem);
        return;
    }

    for (int i = 0; i < num.size(); i ++){
        tem.push_back(num[i]);
        int removeNum = num[i];
        num.erase(num.begin() + i);
        dfs(num,tem);
        tem.pop_back();
        num.insert(num.begin() + i,removeNum);
    }

}
//Obviously, use dfs
    vector<vector<int> > permute(vector<int> &num) {
         result.clear();

        if (num.size() == 0 || num.size() == 1){
            result.push_back(num);
            return result;
        }
        vector<int> tem;
        dfs(num,tem);

        return result;

    }
};
