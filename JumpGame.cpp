/**
 * @file JumpGame.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-09-22
 */
//直接bfs 会memory limited
class Solution {
	public:
    struct Element{
	        int index;
	        int len;
	        Element(int index, int len):index(index), len(len){

			        }
	    };
    bool canJump(int A[], int n) {
	        queue<Element> que;
	        if (n == 1){
			            return true;
			        }
	        Element ele(0, A[0]);
	        que.push(ele);
	        while (!que.empty()){
			            Element tmp = que.front();
			            que.pop();
			            if (tmp.index == n - 1){
						                return true;
						            }
			            for (int i = 1; i <= tmp.len; i ++){
						                if (tmp.index + i <= n - 1){
										                    Element ele(tmp.index + i, A[tmp.index + i]);
										                    que.push(ele);
										                }
						            }
			        }
	        return false;
	    }
};


//正向搜索 找到每一级能够跳转到的最大步数

class Solution {
public:

    bool canJump(int A[], int n) {
       //正向爬  看看最右能到哪里去
       int reach = 1;
       for (int i = 0; i < reach && reach < n; i ++){//最右reach < i说明前面的点无法到达i点
            reach = max (reach, i + 1 + A[i]);
       }
       return reach >= n;
    }
};

//反着下楼梯
class Solution {
public:

    bool canJump(int A[], int n) {
       //反着下楼梯 看看能不能走到0阶梯
       if (n == 0){
           return true;
       }
       int reach = n - 1;
       for (int i = n - 2; i >= 0; i --){
           if (i + A[i] >= reach){
               reach = i;
           }
       }
       return reach == 0;
    }
};

//DP
class Solution {
public:

    bool canJump(int A[], int n) {
      //dp f[i]表示从0走到i的最大剩余步数  转移方程为
      //dp[i] = max(dp[i - 1], A[i - 1]) - 1
      if (n == 0){
          return true;
      }
      vector<int> dp(n, 0);
      dp[0] = A[0];
      for (int i = 1; i < n; i ++){
          dp[i] = max(dp[i - 1], A[i - 1]) - 1;
          if (dp[i] < 0){
              return false;
          }
      }
      return dp[n - 1] >= 0;
    }
};
