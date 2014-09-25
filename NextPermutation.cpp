/**
 * @file NextPermutation.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-09-22
 */
class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int index = num.size() - 1;
        if (index <= 0){
            return ;
        }
        while (index > 0){//找到第一个前面比后面小的位置，从后面看非递增的位置
            if (num[index] > num[index - 1]){
                break;
            }
            index --;
        }
        if (index == 0){//没有找到  说明是一个递减序列，返回逆过来的位置
            reverse(num.begin(), num.end());
        }
        else{
            //如果找到了，从右向左找到第一个比index - 1大的位置 然后交换这两个位置的数
            //再将index后面的序列reverse一下
            int end = num.size() - 1;
            while (num[index - 1] >= num[end]){
                end --;
            }
            swap(num[index - 1], num[end]);
            reverse(num.begin() + index, num.end());
        }
    }
};
