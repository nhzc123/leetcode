/**
 * @file pow.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-09-23
 */

class Solution {
public:
    double pow(double x, int n) {
        if(n==0)return 1;
        if(n==1)return x;
        double temp=pow(x,abs(n/2));
        if(n>0)  //区分正次幂和负数幂
        {
            if(n&1)return temp*temp*x;
            else return temp*temp;
        }
        else
        {
            if(n&1)return 1.0/(temp*temp*x);
            else return 1.0/(temp*temp);
        }
    }
};
