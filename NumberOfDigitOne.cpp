/**
 * @file NumberOfDigitOne.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2015-07-14
 */
class Solution {
public:
/*
以算百位上1为例子:   假设百位上是0, 1, 和 >=2 三种情况:
    case 1: n=3141092, a= 31410, b=92. 计算百位上1的个数应该为 3141 *100 次.
    case 2: n=3141192, a= 31411, b=92. 计算百位上1的个数应该为 3141 *100 + (92+1) 次.
    case 3: n=3141592, a= 31415, b=92. 计算百位上1的个数应该为 (3141+1) *100 次.
*/
    int countDigitOne(int n) {
        if (n <= 0){
            return 0;
        }
        int sum = 0;
        int size = 0;
        int tem = n;
        while (tem){
            size += 1;
            tem /= 10;
        }
        int cur, high, low;
        while (size){
            cur = n / (int)(pow(10, size - 1));
            high = cur / 10;
            cur = cur % 10;
            low = n % (int)(pow(10, size - 1));
            if (cur == 0){
                cur = 1;
            }
            else if (cur == 1){
                cur = 2;
            }
            else{
                cur = 3;
            }
            switch (cur){
                case 1:
                    sum += (high * (pow(10, size - 1)));
                    break;
                case 2:
                    sum += (high * (pow(10, size - 1)) + low + 1);
                    break;
                case 3:
                    sum += ((high + 1) * (pow(10, size - 1)));
                    break;
            }
            size -= 1;
        }

        return sum;
    }
};
