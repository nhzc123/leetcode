/**
 * @file ContainsDuplicate2.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2015-06-01
 */
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> result;
        for (int i = 0; i < nums.size(); i ++){
            if (result.find(nums[i]) != result.end() && i - result[nums[i]] <= k){
                return true;
            }
            result[nums[i]] = i;
        }
        return false;
    }
};
