/**
 * @file Permutation2.cpp
 * @brief
 * @author charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-08-30
 */

class Solution {
public:
vector<vector<int> > result;
bool flag[100] ;
int value[100];
void dfs(int dep,int len,vector<int> &num){
    if (dep == len){
        vector<int> v;

        for (int i = 0; i < len; i ++){
            v.push_back(value[i]);
        }
        result.push_back(v);
        return ;
    }

    for (int i = 0; i < len; i ++){
        if (!flag[i]){

            if (i != 0 && num[i - 1] == num[i] && !flag[i - 1]){
                continue;
            }

            flag[i] = true;
            value[dep] = num[i];
            dfs(dep + 1, len, num);
            flag[i] = false;
        }
    }


}
//Obviously, use dfs
    vector<vector<int> > permuteUnique(vector<int> &num) {
        result.clear();
        memset(flag,false,sizeof(flag));
        int dep = 0;
        //将数组排序，相同的元素排在一起，判断相同元素的前一个元素没有进去递归，则该元素也不递归进去
        sort(num.begin(),num.end());

        dfs(dep,num.size(),num);

        return result;
    }
};
