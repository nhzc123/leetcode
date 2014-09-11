/**
 * @file UniqueBinarySearchTrees.cpp
 * @brief
 * @author charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-09-05
 */

class Solution {
public:
    int numTrees(int n) {
        int dp[1000];
        memset(dp,0,sizeof(dp));
        dp[0] = 1;//当0个节点有1个形状
        dp[1] = 1;//当1个节点有1个形状
        dp[2] = 2;//当2个节点有2个形状
        //超过3个点的时候，先选择中间一个点，然后再左右选择子树，并将其形状相乘，遍历完毕各种左右子树个数即可

        for (int i = 3; i <= n; i ++){
            int sum = 0;

            for (int j = 0; j < i; j ++){
                sum += dp[j] * dp[i - j - 1];
            }
            dp[i] = sum;
        }

        return dp[n];
    }
};
