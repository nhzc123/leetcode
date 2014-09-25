/**
 * @file DivideTwoInteger.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-09-25
 */

class Solution {
public:
    int divide(int dividend, int divisor) {
        //要注意防止溢出 涉及到乘除的一般要考虑到正负号
        bool flag = (dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0);
        unsigned int dividendUnsigned = dividend > 0 ? dividend : -dividend;
        unsigned int divisorUnsigned = divisor > 0 ? divisor : -divisor;
        int result = 0;
        while (dividendUnsigned >= divisorUnsigned){//1. 从最小的除数开始数上去
            int count = 1;
            unsigned int tem = divisorUnsigned;
            while (dividendUnsigned >= tem){//每次除的时候翻倍  翻到无法删除的时候重新回到1
                dividendUnsigned -= tem;
                result += count;
                if (tem < (INT_MAX >> 1)){
                    tem += tem;
                    count += count;
                }
            }
        }
        return flag ? -result : result;
    }
};
