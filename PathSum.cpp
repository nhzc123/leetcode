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

    void dfs(TreeNode *root,int res,int sum,bool &flag){

        if (flag){

            return ;
        }

        res += root->val;

        if (root->left == NULL && root->right == NULL){

            if (res == sum){
                flag = true;

            }
            return ;
        }

        if (root->left != NULL){
            dfs(root->left,res,sum,flag);
        }

        if (root->right != NULL){
            dfs(root->right,res,sum,flag);
        }
    }
    bool hasPathSum(TreeNode *root, int sum) {



        if (root == NULL){
            return false;
        }

        int res = 0;
        bool flag = false;

        dfs(root,res,sum,flag);

        return flag;

    }
};
