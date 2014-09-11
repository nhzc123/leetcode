/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    void compareTree(TreeNode *p, TreeNode *q,bool &flag){
        if(!flag){

            return ;
        }

        if(p == NULL && q != NULL){
            flag = false;
            return ;
        }

        if( p != NULL && q == NULL){
            flag = false;
            return ;
        }

        if(p != NULL && q != NULL){

            if( p -> val != q -> val){

                flag = false;
                return ;
            }
            compareTree(p -> left, q -> left,flag);
            compareTree(p -> right, q -> right, flag);
        }
    }

    bool isSameTree(TreeNode *p, TreeNode *q) {

        bool flag = true;

        compareTree(p,q,flag);

        return flag;
    }
};
