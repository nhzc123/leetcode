/**
 * @file HappyNumber.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2015-04-22
 */
class Solution {
public:
    bool isHappy(int n) {
        map<int, bool> m;
        bool flag = true;
        int result = 0;
        while (n != 1){
            result = 0;
            while(n){
                result += (n % 10) * (n % 10);
                n /= 10;
            }
            if (result == 1){
                return true;
            }
            if (m.find(result) == m.end()){
                m[result] = true;
            }
            else{
                flag = false;
                break;
            }
            n = result;
        }
        return flag;

    }
};
