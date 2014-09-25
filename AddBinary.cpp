/**
 * @file AddBinary.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-09-17
 */

class Solution {
public:
    string addBinary(string a, string b) {
        int upper = 0;
        int lenA = a.length();
        int lenB = b.length();
        string result;
        while (lenA > 0 && lenB > 0){
            int sum = a[lenA - 1] + b[lenB - 1] + upper - '0' - '0';
            switch (sum){
                case 3:{
                    result += '1';
                    upper = 1;
                    break;
                }
                case 2:{
                    result += '0';
                    upper = 1;
                    break;
                }
                case 1:{
                    result += '1';
                    upper = 0;
                    break;
                }
                case 0:{
                    result += '0';
                    upper = 0;
                    break;
                }
            }
            lenA --;
            lenB --;
        }
        while (lenA > 0){
            int sum = a[lenA - 1] - '0' + upper;
            switch (sum){
                case 2:{
                    result += '0';
                    upper = 1;
                    break;
                }
                case 1:{
                    result += '1';
                    upper = 0;
                    break;
                }
                case 0:{
                    result += '0';
                    upper = 0;
                    break;
                }
            }
            lenA --;
        }
        while (lenB > 0){
            int sum = b[lenB - 1] - '0' + upper;
            switch (sum){
               case 2:{
                    result += '0';
                    upper = 1;
                    break;
                }
                case 1:{
                    result += '1';
                    upper = 0;
                    break;
                }
                case 0:{
                    result += '0';
                    upper = 0;
                    break;
                }
            }
            lenB --;
        }
        if (upper == 1){
            result += '1';
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
