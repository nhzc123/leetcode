/**
 * @file MinimumSizeSubarraySum.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2015-05-12
 */
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.size() <= 0){
            return 0;
        }
        int minLen = nums.size() + 1;
        int begin = 0;
        int end = 0;
        int sum = nums[0];

        while (begin <= end){
            if (sum >= s){
                if (minLen > end - begin + 1){
                    minLen = end - begin + 1;
                }
                sum -= nums[begin];
                begin ++;
            }
            else{
                end ++;
                if (end < nums.size()){
                    sum += nums[end];
                }
                else{
                    break;
                }
            }
        }
        if (minLen == nums.size() + 1){
            return 0;
        }
        else{
            return minLen;
        }
    }
};
