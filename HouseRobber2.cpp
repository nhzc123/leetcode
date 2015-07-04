/**
 * @file HouseRobber2.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2015-06-01
 */
class Solution {
public:
    int rob(vector<int>& nums) {

        int houseNum = nums.size();
        if (houseNum == 0){
            return 0;
        }
        if (houseNum == 1){
            return nums[0];
        }
        if (houseNum == 2){
            return nums[0] > nums[1] ? nums[0] : nums[1];
        }
        //第一家抢 最后一家不抢
        int robNow = nums[0];
        int noRob = 0;
        int tem = 0;
        for (int i = 1; i < houseNum - 1; i ++){
            tem = noRob;
            noRob = max(noRob, robNow);
            robNow = tem + nums[i];
        }
        int result1 = max(noRob, robNow);
        robNow = 0;
        noRob = 0;
        //第一家不抢 最后一家抢
        for (int i = 1; i < houseNum - 1; i ++){
            tem = noRob;
            noRob = max(noRob, robNow);
            robNow = tem + nums[i];
        }
        int result2 = max(noRob + nums[houseNum - 1], robNow) ;
        return result1 > result2 ? result1 : result2;
    }
};
