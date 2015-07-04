/**
 * @file TheSkylineProblem.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2015-06-02
 */
class Solution {
public:
//将一层楼的（左节点，高度）和（右节点，高度）存入一个vector中，sort一下按照x坐标排序，然后维护一个heap，如果碰到左节点压入，碰到该右节点弹出，然后出现拐点的位置是当Heap当中的最大值cur与之前的高度不一致，这时候保存该点位置
//http://www.cnblogs.com/easonliu/p/4531020.html
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int> > buildPoint;
        for (auto &b : buildings){
            buildPoint.push_back(make_pair(b[0], -b[2]));//将左节点高度设为负值方便查找
            buildPoint.push_back(make_pair(b[1], b[2]));
        }
        sort(buildPoint.begin(), buildPoint.end());
        multiset<int> heap;
        heap.insert(0);//中间buildPoint要是弹光的时候指针不会出错
        int cur = 0, pre = 0;
        vector<pair<int, int> > result;
        for (auto &point : buildPoint){
            if (point.second < 0){
                heap.insert(-point.second);
            }
            else{
                heap.erase(heap.find(point.second));
            }
            cur = *heap.rbegin();
            if (cur != pre){
                result.push_back(make_pair(point.first, cur));
                pre = cur;
            }
        }
        return result;
    }
};
