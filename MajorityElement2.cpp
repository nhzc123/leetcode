/**
 * @file MajorityElement2.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2015-07-04
 */
class Solution {
	public:
    vector<int> majorityElement(vector<int>& nums) {
	        int length = nums.size();
	        vector<int> result;

	        if (length == 0){
			            return result;
			        }

	        int canditateA = 0, canditateB = 0;
	        int countA = 0, countB = 0;

	        for (int i = 0; i < length; i ++){
			            if (countA == 0){
						                canditateA = nums[i];
						                countA += 1;
						            }
			            else if (canditateA == nums[i]){
						                countA += 1;
						            }
			            else if (countB == 0){
						                canditateB = nums[i];
						                countB += 1;
						            }
			            else if (canditateB == nums[i]){
						                countB += 1;
						            }
			            else{
						                countA -= 1;
						                countB -= 1;
						            }
			        }

	        int actualA = 0, actualB = 0;

	        for (int i = 0; i < length; i ++){
			            if (canditateA == nums[i]){
						                actualA += 1;
						            }
			            else if (canditateB == nums[i]){
						                actualB += 1;
						            }
			        }

	        if (actualA > length / 3){
			            result.push_back(canditateA);
			        }
	        if (actualB > length / 3){
			            result.push_back(canditateB);
			        }

	        return result;
	    }
};
