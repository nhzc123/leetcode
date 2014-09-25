/**
 * @file ValidParenthese.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-09-16
 */

class Solution {
public:
    bool isValid(string s) {
        //压栈弹出栈经典问题 ( { [的话就压进去 然后每次碰到 ) } ]的话就弹出栈  如果不匹配就false了
        if (s == ""){
            return true;
        }
        stack<char> leftStack;
        for (int i = 0; i < s.length(); i ++){
            if (s[i] == '(' || s[i] == '{' || s[i] == '['){
                leftStack.push(s[i]);
            }
            else{
                if (leftStack.empty()){
                    return false;
                }
                else{
                    char tmp = leftStack.top();
                    leftStack.pop();
                    if (s[i] == ')' && tmp != '('){
                        return false;
                    }
                    if (s[i] == '}' && tmp != '{'){
                        return false;
                    }
                    if (s[i] == ']' && tmp != '['){
                        return false;
                    }
                }
            }
        }
        if (leftStack.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};
