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
    void dfs(TreeNode *root,int &sum,int count){

        count = (root->val) + count * 10;

        if (root->left == NULL && root->right == NULL){

            sum += count;

            return ;
        }

        if (root->left != NULL)
            dfs(root->left,sum,count);

        if (root->right != NULL)
            dfs(root->right,sum,count);
    }
    int sumNumbers(TreeNode *root) {

        int sum = 0;

        if (root == NULL){

            return sum;
        }

        dfs(root,sum,0);

        return sum;

    }
};
