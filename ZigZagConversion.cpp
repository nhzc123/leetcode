/**
 * @file ZigZagConversion.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-09-24
 */

class Solution {
public:
    string convert(string s, int nRows) {
       if (s.size() <= 1 || nRows <= 1){
           return s;
       }
       string result = "";
       int len = s.size();
       for (int i = 0; i < nRows && i < len; i ++){//有可能字符串长度都没有行数多
           int index = i;
           result += s[index];
           int k = 1;
           while (index < len){
               if (i == 0 || i == nRows - 1){//如果是第一行或者最后一行
                   index += 2 * nRows - 2;
               }
               else{//如果是中间的行数 那么需要分成奇数列或者偶数列  注意这里的奇数偶数列是指的是每一行的，可以看成从对角线上面
                   //继续走 这时候可以看到下面规则
                   if (k & 0x1){
                        index += 2 * (nRows - i - 1);
                   }
                   else{
                       index += 2 * i;
                   }
                   k ++;
               }
               if (index < len){
                   result += s[index];
               }
           }
       }
       return result;

    }
};
