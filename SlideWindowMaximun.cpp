class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> heap;
        vector<int> result;
        if (k == 0){
            return result;
        }
        for (int i = 0; i < k && i < nums.size(); i ++){
            heap.insert(nums[i]);
        }
        result.push_back(*heap.rbegin());
        if (k >= nums.size()){
            
            return result;
        }
        for (int i = k; i < nums.size(); i ++){
            
            heap.erase(heap.find(nums[i - k]));
            heap.insert(nums[i]);
            result.push_back(*heap.rbegin());
        }
        return result;
    }
};
