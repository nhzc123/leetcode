/**
 * @file MultiplyString.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-09-25
 */

class Solution {
public:
    string multiply(string num1, string num2) {
        //只要跟数字有关 都要问是否正负数
        if (num1 == "0" || num2 == "0"){
            return "0";
        }
        int len1 = num1.size();
        int len2 = num2.size();
        int *result = new int[len1 + len2];
        for (int i = 0; i < len1 + len2; i ++){
            result[i] = 0;
        }
        for (int i = 0; i < len1; i ++){//将对应位置的数字相加
            for (int j = 0; j < len2; j ++){
                result[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
            }
        }
        //将有进位的数字加上去
        string s = "";
        for (int i = len1 + len2 - 1; i >= 0; i --){
            if (i > 0){//超过10的话进位到上一位
                result[i - 1] += result[i] / 10;
            }
            result[i] %= 10;
            s = char(result[i] + '0') + s;
        }
        return s[0] == '0' ? s.substr(1) : s;

    }
};
