/**
 * @file FractionToRecurringDecimal.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2015-04-19
 */
#include<iostream>
#include<string>
#include<map>
using namespace std;
    string fractionToDecimal(int numerator, int denominator) {
        //反过来 0.（6）转化方法如下：
        // 6.666* 10 - 0.666 = 6
        // 0.666 * (10 - 1) = 6
        // 0.666 = 6 / 9 = 2 / 3
        if (numerator == 0){
            return "0";
        }
        string result = "";
        if((numerator<0 && denominator>0) || ((numerator > 0) && (denominator < 0)) ) result+='-';
		cout<<result<<endl;
        long long int n = numerator, d = denominator;
		n = abs(n);
		d = abs(d);
        result += to_string(n / d);
        long long int r = n % d;
        if (r == 0){
            return result;
        }
        else{
            result += '.';
        }
        map<int, int> m;
        while(r){
			cout<<result<<endl;
			cout<<r<<" "<<d<<endl;
            if (m.find(r) != m.end()){
                result.insert(m[r], 1, '(');
                result += ')';
                break;
            }
            m[r] = result.size();
            r *= 10;
            result += to_string(r / d);
            r %= d;
        }
        return result;

    }
int main(){
cout<<fractionToDecimal(-1,-2147483648)<<endl;


return 0;
}
