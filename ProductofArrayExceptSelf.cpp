class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result;
        if (nums.size() == 0 || nums.size() == 1){
            return nums;
        }
        vector<int> tem1(nums.size(), 1);
        vector<int> tem2(nums.size(), 1);
        for (int i = 1, j = nums.size() - 2; i < nums.size(); i ++, j --){
            tem1[i] = tem1[i - 1] * nums[i - 1];
            tem2[j] = tem2[j + 1] * nums[j + 1];
        }
        for (int i = 0; i < nums.size(); i ++){
            result.push_back(tem1[i] * tem2[i]);
        }
        return result;
    }
};
