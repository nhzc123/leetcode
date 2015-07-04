/**
 * @file MajorityElement.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-12-24
 */

class Solution {
public:
    int majorityElement(vector<int> &num) {
        if (num.size() == 1){
            return num[0];
        }
        int nTime = 0;
        int canditate = 0;
        for (int i = 0; i < num.size(); i ++){
            if (nTime == 0){
                canditate = num[i];
                nTime = 1;
            }
            else{
                if (canditate == num[i]){
                    nTime ++;
                }
                else{
                    nTime --;
                }
            }
        }
        return canditate;

    }
};
