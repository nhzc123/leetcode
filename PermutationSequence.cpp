/**
 * @file PermutationSequence.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-09-25
 */

class Solution {
public:
    string getPermutation(int n, int k) {
        //排列组合问题，第n位后面的排列组合数总共有(n - 1)!
        int i, j, fact[10], flag[10];
        fact[0] = fact[1] = 1;//阶乘
        memset(flag, 0, sizeof(flag));//该位数字是否已经出现
        for (i = 2; i <= n; i ++){
            fact[i] = fact[i - 1] * i;
        }
        i -= 2;
        k --;
        string s = "";
        while (i >= 0){
            int tmp = k / fact[i];
            for (j = 1; j < 10; j ++){
                if (flag[j] == 0){
                    tmp --;
                }
                if (tmp < 0){
                    break;
                }
            }
            flag[j] = 1;
            s += j + '0';
            k %= fact[i];
            i --;
        }
        return s;
    }
};
