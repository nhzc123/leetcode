/**
 * @file LengthOfLastWord.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-09-16
 */

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int len = 0;

        while(s[len ++] != '\0');
        len --;
        if (len <= 0){
            return 0;
        }
        int count = 0;
        int i = len - 1;
        for (; i >= 0; i --){
            if (s[i] == ' '){
                continue;
            }
            else{
                break;
            }
        }
        if (i < 0){
            return 0;
        }
        for (;i >= 0; i --){
            if (s[i] == ' '){
                return count;
            }
            else{
                count ++;
            }
        }
        return count;

    }
};
