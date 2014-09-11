/**
 * @file sqrtx.cpp
 * @brief
 * @author charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-08-30
 */
class Solution {
public:
    int sqrt(int x) {
        //二分方法，平方和到x的数绝对比x的一半还要小
        //牛顿迭代法求平方根
        if ( x == 0){
            return 0;
        }
        double cur = 1;
        double pre = cur;

        while (true){
            pre = cur;
            cur = pre - (pre * pre - x) / (2 * pre);

            if (abs(cur - pre) < 0.00001){
                return int(cur);
            }
        }
    }
};
