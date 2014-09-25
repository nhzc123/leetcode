/**
 * @file LargestRectangleHistogram.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-09-15
 */
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        //使用递增栈的思想来分析可参照http://blog.csdn.net/doc_sgl/article/details/11805519
        //大概意思是说从左往右边扫描， 如果碰到比当前stack大的数就入栈，如果小的话就依次弹栈，计算弹出来的栈与当前位置之间的最大
        //值，注意压入的是当前的位置而非高度
        stack<int> s;
        int result = 0;
        height.push_back(0);//在最后面压入0，可以保证压栈到最后全部都弹出来
        for (int i = 0; i < height.size(); i){
            if (s.empty() || height[i] > height[s.top()]){
                s.push(i ++);//递增栈的话就压入
            }
            else{//否则 计算当前的最大值
                int tmp = s.top();
                s.pop();//将最大值弹出
                result = max(result, height[tmp] * (s.empty() ? i : i - s.top() - 1));
            }
        }
        return result;

    }
};
