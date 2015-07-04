/**
 * @file BasicCalculator2.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2015-06-22
 */
class Solution {
public:
//http://www.cnblogs.com/wanghetao/archive/2012/04/23/2466580.html
//标准求解逆波兰表达式
/*一、 将中缀表达式转换成后缀表达式算法：
1、从左至右扫描一中缀表达式。
2、若读取的是操作数，则判断该操作数的类型，并将该操作数存入操作数堆栈
3、若读取的是运算符
  (1) 该运算符为左括号"("，则直接存入运算符堆栈。
  (2) 该运算符为右括号")"，则输出运算符堆栈中的运算符到操作数堆栈，直到遇到左括号为止。
  (3) 该运算符为非括号运算符：
      (a) 若运算符堆栈栈顶的运算符为括号，则直接存入运算符堆栈。
      (b) 若比运算符堆栈栈顶的运算符优先级高，则直接存入运算符堆栈。
      (c) 若比运算符堆栈栈顶的运算符优先级低或相等，则输出栈顶运算符到操作数堆栈，并将当前运算符压入运算符堆栈。
4、当表达式读取完成后运算符堆栈中尚有运算符时，则依序取出运算符到操作数堆栈，直到运算符堆栈为空。

二、逆波兰表达式求值算法：
1、循环扫描语法单元的项目。
2、如果扫描的项目是操作数，则将其压入操作数堆栈，并扫描下一个项目。
3、如果扫描的项目是一个二元运算符，则对栈的顶上两个操作数执行该运算。
4、如果扫描的项目是一个一元运算符，则对栈的最顶上操作数执行该运算。
5、将运算结果重新压入堆栈。
6、重复步骤2-5，堆栈中即为结果值。
*/
    int calculate(string s) {
        vector<string> polish;
        stack<char> oper;
        int i = 0;
        while (i < s.size()){
            if (s[i] == ' '){
                i ++;
                continue;
            }
            if ((s[i] - '0') >= 0 && (s[i] - '0') <= 9){
                string sum = "";
                while ((s[i] - '0') >= 0 && (s[i] - '0') <= 9){
                    sum += s[i];
                    i ++;
                }

                polish.push_back(sum);
            }
            else if (s[i] == '('){
                oper.push('(');
                i ++;
            }
            else if (s[i] == ')'){
                while (oper.top() != '('){
                    string sTem = "";
                    sTem += oper.top();
                    polish.push_back(sTem);
                    oper.pop();
                }
                oper.pop();
                i ++;
            }
            else if (s[i] == '+' || s[i] == '-'){
                if (oper.empty()){
                    oper.push(s[i]);
                    i ++;
                }
                else{
                    if (oper.top() == '('){
                        oper.push(s[i]);
                        i ++;
                    }
                    else {
                        while (!oper.empty()){
                            string sTem = "";
                            sTem += oper.top();
                            polish.push_back(sTem);
                            oper.pop();
                        }
                            oper.push(s[i]);
                            i ++;


                        }

                }
            }
            else{
                  if (oper.empty()){
                    oper.push(s[i]);
                    i ++;
                }
                else{
                    if (oper.top() == '+' || oper.top() == '-'){
                        oper.push(s[i]);
                         i ++;
                    }
                    else{
                        while (!oper.empty() &&(oper.top() == '*' || oper.top() == '/')){
                            string sTem = "";
                            sTem += oper.top();
                            polish.push_back(sTem);
                            oper.pop();
                        }
                            oper.push(s[i]);
                            i ++;

                    }
                }
            }
        }
        while (!oper.empty()){
            string sTem = "";
            sTem += oper.top();
            polish.push_back(sTem);
            oper.pop();
        }

        int sum = 0;
        stack<double> sNum;
        for (int i = 0; i < polish.size(); i ++){

            if (polish[i] != "+" && polish[i] != "-" && polish[i] != "*" && polish[i] != "/"){
                double sum = 0;
                for (int j = 0; j < polish[i].size(); j ++){
                    sum = sum * 10 + (polish[i][j] - '0');
                }
                sNum.push(sum);
            }
            else{
               double a = sNum.top();
                sNum.pop();
                double b = sNum.top();
                sNum.pop();
                if (polish[i] == "+"){
                    sNum.push(a + b);
                }
                else if (polish[i] == "-"){
                    sNum.push(b - a);
                }
                else if(polish[i] == "*"){
                    sNum.push(a * b);
                }
                else{
                    sNum.push((int)(b / a));
                }
            }
        }
        return sNum.empty() ? 0 : sNum.top();
    }
};
