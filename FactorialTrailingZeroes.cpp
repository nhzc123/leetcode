/**
 * @file FactorialTrailingZeroes.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2015-04-19
 */
class Solution {
public:
    int trailingZeroes(int n) {
        int result = 0;
        while (n){
            result += (n /= 5);
        }
        return result;
    }
};
