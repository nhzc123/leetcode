class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        sort(num.begin(),num.end());
        vector<vector<int> > result;
        int len = num.size();
        for (int i = 0; i < len; i++){
            int j = i + 1;
            int k = len - 1;
            while (j < k){
                if (num[i] + num[j] + num[k] == 0){
                    vector<int> tem;
                    tem.push_back(num[i]);
                    tem.push_back(num[j]);
                    tem.push_back(num[k]);
                    result.push_back(tem);
                    while ( j + 1 < len && num[j] == num[j + 1]){
                        j++;
                    }
                    while ( k - 1 >= 0 && num[k] == num[k - 1]){
                        k--;
                    }
                    j++;
                    k--;
                }
                else if (num[i] + num[j] + num[k] > 0){
                    k--;
                }
                else{
                    j++;
                }
            }
            while ( i + 1 < len && num[i] == num[i + 1]){
                i++;
            }
        }

        return result;

    }
};
