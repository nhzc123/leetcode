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
    int maxLength = 0;

    void findDepth(TreeNode *root, int count){

        if( root == NULL){

            if( count > maxLength)
                maxLength = count ;
            return ;
        }

        findDepth(root -> left, count + 1);
        findDepth(root -> right, count + 1);

    }
    int maxDepth(TreeNode *root) {

        findDepth(root,0);

        return maxLength;

    }
};
