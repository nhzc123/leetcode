/**
 * @file HouseRobber.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2015-04-19
 */
class Solution {
public:
    int rob(vector<int> &num) {
        int rob = 0;
        int noRob = 0;
        int tem = 0;
        for (int i = 0; i < num.size(); i ++){
            tem = noRob;
            noRob = max(noRob, rob);
            rob = tem + num[i];
        }
        return max(rob, noRob);
    }
};
