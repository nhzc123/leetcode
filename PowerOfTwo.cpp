/**
 * @file PowerOfTwo.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2015-07-07
 */
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 1){
            return true;
        }

        if (n <= 0){
            return false;
        }

        n &= (n - 1);

        if (n){
            return false;
        }
        else{
            return true;
        }


    }
};
