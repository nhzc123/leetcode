/**
 * @file ContainsDuplicate.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2015-06-01
 */
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> result;
        if (nums.size() == 0){
            return false;
        }
        for (auto &num : nums){
            if (result.find(num) != result.end()){
                return true;
            }
            result.insert(num);
        }
        return false;
    }
};
