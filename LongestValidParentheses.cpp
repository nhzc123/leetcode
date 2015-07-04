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

http://blog.csdn.net/zhangwei1120112119/article/details/16812679

stack<int> s;
s.push_back(-1);
int ans = 0;
for (int i = 0; i < str.length(); i ++){
	if (str[i] == '('){
		s.push_back(i);

		}
	else{
		if (s.size() > 1){
			s.pop();
			tem = s.top();
			ans = max(ans, i - tem);
		}
		else{
			s.pop();
			s.push(i);
		}
	}

}
