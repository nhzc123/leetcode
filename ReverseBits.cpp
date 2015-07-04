/**
 * @file ReverseBits.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2015-04-19
 */
class Solution {
	public:
    uint32_t reverseBits(uint32_t n) {
	        uint32_t result = 0;
	        int step = 31;
	        while (n){
			            result += ((n & 1) ? pow(2, step) : 0);
			            n >>= 1;
			            step --;
			        }
	        return result;
	    }
};
