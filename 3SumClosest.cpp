class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int delta = INT_MAX;
        int closeSet = 0;
        int len = num.size();
        sort(num.begin(),num.end());
        for (int i = 0; i < len; i++){
            int j = i + 1;
            int k = len - 1;
            while (j < k){
                int sum = num[i] + num[j] + num[k];
                if (abs(sum - target) < delta){
                    delta = abs(sum - target);
                    closeSet = sum;
                }

                if (sum == target){
                    return target;
                }
                else if (sum > target){
                    k --;
                }
                else{
                    j++;
                }


            }
        }
        return closeSet;
    }
};
