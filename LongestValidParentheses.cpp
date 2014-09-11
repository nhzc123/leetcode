/**
 * @file LongestValidParentheses.cpp
 * @brief
 * @author charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-09-04
 */
class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.length() == 0 || s.length() == 1){
            return 0;
        }
        stack<int> pStack;
        int longest = 0;
        int unmatchPos = 0;

        for (int i = 0; i < s.size(); i ++){
            if (s[i] == '('){
                pStack.push(i);
            }
            else{
                if (!pStack.empty()){
                    pStack.pop();
                    if (!pStack.empty()){
                        longest = max(longest, i - pStack.top());
                    }
                    else{
                        longest = max(longest, i - unmatchPos + 1);
                    }
                }
                else{
                    unmatchPos = i + 1 ;
                }
            }
        }

        return longest;

    }
};
