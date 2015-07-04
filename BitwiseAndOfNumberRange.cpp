/**
 * @file BitwiseAndOfNumberRange.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2015-04-19
 */
class Solution {
public:
//最低跟最高的前缀相同的时候就是了
    int rangeBitwiseAnd(int m, int n) {
        int offset = 0;
        while(m && n){
            if (m != n){

            }
            else{
                return m << offset;
            }
            m >>= 1;
            n >>= 1;
            offset += 1;
        }
        return 0;
    }
};
