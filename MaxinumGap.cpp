/**
 * @file MaxinumGap.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-12-14
 */

class Solution {
public:
    int maximumGap(vector<int> &num) {
        if (num.size() < 2){
            return 0;
        }
        sort(num.begin(),num.end());
        int result = 0;
        for (int i = 0; i < num.size() - 1; i ++){
            int diff = num[i + 1] - num[i];
            if (diff > result){
                result = diff;
            }
        }
        return result;

    }
};

class Solution {
public:
    int maximumGap(vector<int> &num) {
        if (num.size() < 2){
            return 0;
        }
        int n = num.size();
        int maxValue = *max_element(num.begin(), num.end());
        int minValue = *min_element(num.begin(), num.end());
        int maxGap = 1;
        vector<int> maxIdx(n, -1);
        vector<int> minIdx(n, -1);
        //利用分块的思想  把从min 到 max的数字分成了n - 1块，每块都抽象出一个max,和min,然后前一块的min跟后一块的max相减就是gap，取最大的gap作为结果
        for (int i = 0; i < n ; i ++){
            int index = ((double)(num[i] - minValue) * (n - 1)) / (maxValue - minValue);
            if (num[i] > maxIdx[index]){
                maxIdx[index] = num[i];
            }
            if (num[i] < minIdx[index] || minIdx[index] == -1){
                minIdx[index] = num[i];
            }
        }
        int i = 0;
        int j = 1;
        while (j < n){
            while (j < n && minIdx[j] == -1){
                j ++;
            }
            maxGap = (maxGap > minIdx[j] - maxIdx[i]) ? maxGap : minIdx[j] - maxIdx[i];
            i = j;
            j ++;
        }
        return maxGap;
    }
};
