/**
 * @file WildcardMatching.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-09-18
 */
//递归版本 超时
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        //同regular类似 只是*可以匹配任意字符
        if (s == NULL || p == NULL){
            return false;
        }
        if (*p == '\0'){
            return *s == '\0';
        }
        if (*p == '*'){
            while (*p == '*') p ++;
            while (*s != '\0'){
                if (isMatch(s, p)){//和regular的不同在于它只将*号跳过
                    return true;
                }
                s ++;
            }
            return isMatch(s, p);

        }
        else{
            if ((*s != '\0' &&*p == '?') ||  *p == *s){
                return isMatch(s + 1, p + 1);
            }
            else{
                return false;
            }
        }


    }
};
