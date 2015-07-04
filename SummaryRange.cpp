/**
 * @file SummaryRange.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2015-06-27
 */
class Solution {
public:
string format(int begin, int end, vector<int> &nums)
	{
		char buffer[32];
		if (end == begin)
		{
			sprintf(buffer, "%d", nums[begin]);
		}else{
			sprintf(buffer, "%d->%d", nums[begin], nums[end]);
		}
		return string(buffer);
	}
//两个指针 start , end 如果nums[end + 1] = num[end] + 1 移动 否则加入结果集
    vector<string> summaryRanges(vector<int>& nums) {
        int start = 0, end = 0;
        vector<string> result;
        if (nums.size() < 1){
            return result;
        }
        while (end < nums.size()){
            if (end + 1 < nums.size() && nums[end + 1] == nums[end] + 1){
                end ++;
            }
            else{
                result.push_back(format(start, end, nums));
                end ++;
                start = end;
            }
        }

        return result;
    }
};
