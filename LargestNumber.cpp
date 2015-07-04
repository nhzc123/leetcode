/**
 * @file LargestNumber.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2015-07-04
 */
class Solution {
	public:
    static bool cmp(const string &a, const string &b){
	        return (a + b) > (b + a);
	    }
    string largestNumber(vector<int>& nums) {
	        vector<string> strNum(nums.size());
	        for (int i = 0; i < nums.size(); i ++){
			            strNum[i] = to_string(nums[i]);
			        }
	        sort(strNum.begin(), strNum.end(), cmp);
	        string result = "";
	        bool flag = false;
	        for(int i = 0; i < nums.size(); i ++){
			            if (strNum[i] != "0"){
						                result += strNum[i];
						                flag = true;
						            }
			            else if (flag){
						                result += strNum[i];
						            }
			        }
	        if (!flag){
			            result += '0';
			        }
	        return result;
	    }
};
