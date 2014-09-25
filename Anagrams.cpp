/**
 * @file Anagrams.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-09-24
 */

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        //题目的意思是找出所有在str中字母个数相同的字符串，返回第一个的数值
        map<string, int> m; //记录第一次出现的str的位置和名字
        vector<string> result;
        for (int i = 0; i < strs.size(); i ++){
            string s = strs[i];
            sort(s.begin(), s.end());
            if (m.find(s) == m.end()){//如果没在m中出现，则将该位置储存起来
                m[s] = i;
            }
            else{//如果已经出现了
                if (m[s] == -1){
                    result.push_back(strs[i]);
                }
                else{
                    result.push_back(strs[m[s]]);
                    m[s] = -1;
                    result.push_back(strs[i]);
                }
            }
        }
        return result;
    }
};
