class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        sort(num.begin(),num.end());
        vector<vector<int> > result;
        int len = num.size();
        for (int i = 0; i < len -3; i++){

            for (int j = len - 1; j > i + 2; j --){

                int k = i + 1;
                int z = j - 1;
                while (k < z){
                    if (num[i] + num[j] + num[k] + num[z] == target){
                        vector<int> tem;
                        tem.push_back(num[i]);
                        tem.push_back(num[k]);
                        tem.push_back(num[z]);
                        tem.push_back(num[j]);
                        result.push_back(tem);
                        while (k + 1 < z && num[k] == num[k + 1]){
                            k ++;
                        }
                        while (z - 1 > k && num[z] == num[z - 1]){
                            z --;
                        }
                        k++;
                        z--;
                    }
                    else if ( num[i] + num[j] + num[k] + num[z] > target){
                        z --;
                    }
                    else {
                        k ++;
                    }
                }
                 while (j - 1> i + 2 && num[j] == num[j - 1]){
                    j--;
                }
            }
             while ( i + 1 < len -3 && num[i] == num[i + 1]){
                i ++;
            }
        }
        return result;
    }
};
