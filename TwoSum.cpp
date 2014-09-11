struct Node{
    int num;
    int pos;
};
bool cmp(Node a, Node b){
    return a.num < b.num;
}

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> result;
        vector<Node> nodes;
        for (int i = 0; i < numbers.size(); i++){
            Node tem ;
            tem.num = numbers[i];
            tem.pos = i + 1;
            nodes.push_back(tem);
        }
        sort(nodes.begin(),nodes.end(),cmp);
        int i = 0;
        int j = numbers.size() - 1;
        while (i < j){
            if (nodes[i].num + nodes[j].num == target){
                if (nodes[i].pos > nodes[j].pos){
                    result.push_back(nodes[j].pos);
                    result.push_back(nodes[i].pos);
                }
                else{
                    result.push_back(nodes[i].pos);
                    result.push_back(nodes[j].pos);
                }
                break;
            }
            else if (nodes[i].num + nodes[j].num > target){
                j--;
            }
            else{
                i++;
            }
        }
        return result;
    }
};
