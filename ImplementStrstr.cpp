/**
 * @file ImplementStrstr.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-09-17
 */

class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        int lenA = strlen(haystack);
        int lenB = strlen(needle);
        if (lenA < lenB){
            return nullptr;
        }
        if (lenA == lenB){
            if (strcmp(haystack, needle) == 0){
                return haystack;
            }
            return nullptr;
        }
       // bool flag = false;
        int i, j;
        for ( i = 0; i <= lenA - lenB; i ++){
            bool flag = false;
            for ( j = 0; j < lenB; j ++){
                if (haystack[i + j] != needle[j]){
                    flag = true;
                    break;
                }
            }
            if (!flag){
                return haystack + i;
            }
        }

    }
};
