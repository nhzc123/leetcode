/**
 * @file BasicCalculator.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2015-06-10
 */
class Solution {
public:
//注意需要用逆波兰表达式求解
//去除空格 如果碰到(号的话将（号压入到符号表里面去，将数字压入到数据栈里面去
    int calculate(string s) {
        int len = s.size();
        int i = 0;
        stack<char> opt;
        stack<int> nums;
        char c;
        int num;
        while(i < len){
            while (s[i] == ' '){
                i ++;
            }
            c = s[i];
            if (c >= '0' && c <= '9'){
                num = c - '0';
                i ++;
                while (i < len && s[i] >= '0' && s[i] <= '9'){
                    num = num * 10 + s[i++] - '0';
                }
                if (!opt.empty()){
                    if (opt.top() == '+'){
                        opt.pop();
                        int a = nums.top();
                        nums.pop();
                        nums.push(a + num);

                    }
                    else if (opt.top() == '-'){
                        opt.pop();
                        int a = nums.top();
                        nums.pop();
                        nums.push(a - num);
                    }
                    else{
                        nums.push(num);
                    }
                }
                else{
                    nums.push(num);
                }
            }
            else if(c == ')'){
                opt.pop();
                if (!opt.empty()){
                    int a = nums.top();
                    nums.pop();
                    int b = nums.top();
                    nums.pop();
                    if (opt.top() == '+'){
                        nums.push(a + b);
                    }
                    else{
                        nums.push(b - a);
                    }
                    opt.pop();
                }
                i ++;
            }
            else{
                opt.push(c);
                i ++;
            }
        }
        return !nums.empty() ? nums.top() : 0;
    }
};
