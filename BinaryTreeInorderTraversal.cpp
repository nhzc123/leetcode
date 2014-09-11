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

        stack<TreeNode *> s;
        vector<int> ans;
        if(root == NULL){

            return ans;
        }

        TreeNode * cur = root;
        while( !s.empty() || cur != NULL){

            if( cur != NULL){

                s.push(cur);
                cur = cur->left;
            }
            else{

                cur = s.top();
                s.pop();
                ans.push_back(cur->val);
                cur = cur->right;
            }
        }

        return ans;

    }
};
