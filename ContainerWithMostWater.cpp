/**
 * @file ContainerWithMostWater.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2015-04-23
 */
class Solution {
public:
    int maxArea(vector<int> &height) {
        //单纯的在图形中找出两条垂直线，所能装下的最大面积，从宽度最长开始计算，每次变换高度比较低的方向
        int start = 0;
        int end = height.size() - 1;

        int result = 0;

        while (start < end){
            int areas = min(height[end], height[start]) * (end - start);
            result = max(result, areas);

            if (height[end] >= height[start]){
                start ++;
            }
            else{
                end --;
            }
        }

        return result;
    }
};
