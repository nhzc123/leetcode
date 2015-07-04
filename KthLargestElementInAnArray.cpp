/**
 * @file KthLargestElementInAnArray.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2015-06-01
 */
class Solution {
public:
//类似快排的方法
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0;
        int right = nums.size() - 1;
        int lp , rp;
        int index;
        while (left < right){
            lp = left;
            rp = right;
            index = nums[lp];
            while (lp < rp){
                while (lp < rp &&nums[rp] < index ){
                    rp --;
                }
                nums[lp] = nums[rp];
                while (lp < rp && nums[lp] >= index){
                    lp ++;
                }
                nums[rp] = nums[lp];
            }
            nums[lp] = index;
            if (lp == k - 1){
                return nums[k - 1];
            }
            else if(lp < k - 1){
                left = lp + 1;
            }
            else{
                right = lp - 1;
            }

        }
         return nums[k - 1];
    }
};
