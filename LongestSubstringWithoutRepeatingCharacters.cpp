/**
 * @file LongestSubstringWithoutRepeatingCharacters.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-09-17
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //直接扫一遍 记录每一个字母出现的位置下标，当出现重复字母的时候，为了查找更长的字母位置，子串开始的位置需要设置为重复
        //字母的位置
        int alpha[256];
        memset(alpha, -1, sizeof(alpha));
        int result = 0;
        int start = 0;
        for (int i = 0; i < s.length(); i ++){
            if (alpha[s[i]] >= start){//扫描到的位置已经在前面出现过了，并且出现的位置在start的后面(在start前面的可以忽略，因为)
            //已经扫过去了
                start = alpha[s[i]] + 1;
                 alpha[s[i]] = i;
            }
            else{
                alpha[s[i]] = i;
                result = max (result, i - start + 1);
            }
        }
        return result;
    }
};
