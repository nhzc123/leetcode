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
    vector<int> preorderTraversal(TreeNode *root) {

        vector<int> ans;

        if( root == NULL){
            return ans;
        }

        stack<TreeNode *> s;
        s.push( root);
        TreeNode * cur;

        while( !s.empty()){

            cur = s.top();
            s.pop();
            ans.push_back(cur->val);

            if( cur->right != NULL){
                s.push( cur->right);
            }

            if( cur->left != NULL){
                s.push( cur->left);
            }
        }

        return ans;

    }
};
