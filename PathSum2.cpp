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

    void dfs(TreeNode *root,int res,vector<int> tmp,vector<vector<int> > &v,int sum){

        res += root->val;
        tmp.push_back(root->val);

        if (root->left == NULL && root->right == NULL && res == sum){

            v.push_back(tmp);
        }

        if (root->left != NULL){
            dfs(root->left,res,tmp,v,sum);
        }
        if (root->right != NULL){
            dfs(root->right,res,tmp,v,sum);
        }


    }
    vector<vector<int> > pathSum(TreeNode *root, int sum) {

        vector<vector<int> > v;
        int res = 0;
        vector<int> tmp;

        if (root == NULL){

            return v;
        }

        dfs (root,res,tmp,v,sum);

        return v;

    }
};
