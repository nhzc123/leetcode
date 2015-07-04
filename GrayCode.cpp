/**
 * @file GrayCode.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-09-11
 */

class Solution {
public:
    vector<int> grayCode(int n) {
        //格雷码 连续两个数之间相差只有一个位
        //二进制码->格雷码（编码）：从最右边一位起，依次将每一位与左边一位异或（XOR），作为对应格雷码该位的值，最左边一位不变（相当于左边是0）；
        //格雷码->二进制码（解码）：从左边第二位起，将每位与左边一位解码后的值异或，作为该位解码后的值（最左边一位依然不变）。
        //因此n代表的数字总共有1 << n个
        int size = 1 << n;
        vector<int> result;
        for (int i = 0; i < size; i ++){
            result.push_back((i >> 1) ^ i);
        }
        return result;
    }
};


grayToInt(int x){
	int y = x;
	while (x >>= 1){
		y ^= x;
	}
	return x;
}
