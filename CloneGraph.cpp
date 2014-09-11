/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {

        if ( node == NULL){

            return NULL;
        }

        map<int,UndirectedGraphNode *> clone;
        queue<UndirectedGraphNode *> q;

        q.push(node);

        while (!q.empty()){

            UndirectedGraphNode * tmp = q.front();
            q.pop();

            if (clone.find(tmp -> label) == clone.end()){

                UndirectedGraphNode * cloneTmp = new UndirectedGraphNode(tmp -> label);
                clone[tmp -> label] = cloneTmp;

                for (int i = 0; i < tmp -> neighbors.size(); i++){
                    q.push(tmp -> neighbors[i]);
                }
            }
        }

        q.push(node);

        while (!q.empty()){

            UndirectedGraphNode * tmp = q.front();
            q.pop();

            if (clone[tmp -> label] -> neighbors.empty() && !tmp -> neighbors.empty()){

                for ( int i = 0; i < tmp -> neighbors.size(); i++){
                    clone[tmp -> label] ->neighbors.push_back(clone[ tmp -> neighbors[i] -> label]);
                    q.push(tmp -> neighbors[i]);
                }
            }
        }

        return clone[node -> label];
    }
};
