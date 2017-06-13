ass Solution {
public:
//int整数在java中是按照补码的方式来的，那么正数和它负值按位与的结果是原始最右边非0位的数字为1，其余位都为0；
//&的优先级小于==的优先级。
    vector<int> singleNumber(vector<int>& nums) {
        int len = nums.size();
        vector<int> result;
        if (len == 0){
            return result;
        }
        int sum = 0;
        for (int i = 0; i < len; i ++){
            sum ^= nums[i];
        }
        int single1 = 0;
        int single2 = 0;
        int count = 0;
        while ((sum & 1) == 0){
            count ++;
            sum >>= 1;
        }
        for (int i = 0; i < len; i ++){
            if (((nums[i] >> count) & 1) == 0){
                single1 ^= nums[i];
            }
            else{
                single2 ^= nums[i];
            }
        }
        result.push_back(single1);
        result.push_back(single2);
        return result;
    }
};
