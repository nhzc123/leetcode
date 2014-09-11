/**
 * @file LongestCommonPrefix.cpp
 * @brief
 * @author charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-08-31
 */

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string result;

        if (strs.size() == 0){
            return result;
        }

        string tem1 = strs[0];

        if (tem1.size() == 0){
            return result;
        }
        for (int i = 1; i < strs.size(); i ++){
            if (strs[i].size() == 0){
                return result;
            }

            string tem2 = strs[i];

            int len1 = tem1.size();
            int len2 = tem2.size();
            int len = min(len1, len2);
            string tem = "";

            for (int i = 0; i < len1; i ++){
                if (tem1[i] == tem2[i]){
                    tem += tem1[i];
                }
                else{
                    break;
                }
            }

            tem1 = tem;



        }

        return tem1;

    }
};
