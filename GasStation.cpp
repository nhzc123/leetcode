class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {

       int total = 0;
       int sum = 0;
       int start = 0;

       //每一个站点的代价都是gas - cost
       //求总代价，小于0则不成立 大于0求从0开始的代价，如果某部分小于0 那么开头不可能从该位置或者之前的位置开始（因为有积累） 必须从该
       //位置以后的站点开始作为开头的计算
       for (int i = 0;i < gas.size(); i++){

           total += gas[i] - cost[i];
           sum += gas[i] = cost[i];

           if (sum < 0){

               start = (i + 1) % gas.size();
               sum = 0;
           }
       }

       if (total < 0){

           return  -1;
       }
       else {

           return start;
       }


    }
};
