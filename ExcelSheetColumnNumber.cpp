/**
 * @file ExcelSheetColumnNumber.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2015-04-19
 */
class Solution {
public:
    int titleToNumber(string s) {
        int result = 0;
        if (s.empty()){
            return result;
        }

        for (int i = 0; i < s.length(); i++){
            result += (s[i] - 'A' + 1) * pow(26, s.length() - i - 1);
        }
        return result;
    }
};
