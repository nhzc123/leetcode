/**
 * @file PalindromeNumber.cpp
 * @brief
 * @author charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-09-07
 */
class Solution {
public:


    bool isPalindrome(int x) {
        //负数，将整数转化成string需要额外的空间，反转整数会导致溢出
        if (x < 0){
            return false;
        }
        if (x == 0){
            return true;
        }

        int base = 1;

		//找到最左边的位置
        while (x / base >= 10){
            base *= 10;
        }

        while (x){
            int left = x / base;
            int right = x % 10;

            if (left != right){
                return false;
            }

			//减掉左边
            x -= left * base;
			//每次减小两个数 所以base / 100
            base /= 100;
			//减掉右边
            x /= 10;
        }

        return true;
    }
};
