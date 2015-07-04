/**
 * @file ExcelSheetColumnTitle.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2015-04-19
 */
class Solution {
public:
    string convertToTitle(int n) {
        if(n < 1){
            return "";
        }
        string result = "";
        while(n){
            n --;
            result += ((n % 26) + 'A');
            n /= 26;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
