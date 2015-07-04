/**
 * @file FindPeakElement.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-12-07
 */
//http://blog.csdn.net/doc_sgl/article/details/41991809
//因为最左边和最右边都是最小 所以第一个出现左边大于右边的就是了

class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        int low = 0;
        int high = num.size() - 1;

        while (low < high){
            //int mid1 = high - (high - low) / 2;
            int mid1 = low - (low - high) / 2;
           // int mid1 = (high + low) / 2;
            int mid2 = mid1 + 1;

            if (num[mid1] < num[mid2]){
                low = mid2;
            }
            else{
                high = mid1;
            }
        }
        return low;

    }
};
