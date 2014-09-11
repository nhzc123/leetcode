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
    vector<int> postorderTraversal(TreeNode *root) {

        vector<int> ans;
        if(root == NULL){

            return ans;

        }
        ans.clear();
        stack<TreeNode *> s;
        stack<TreeNode *> result;

        s.push(root);


        while( !s.empty()){

            TreeNode *tem = s.top();
            s.pop();
            result.push(tem);

            if( tem->left != NULL){

                s.push(tem->left);
            }

            if( tem->right != NULL){

                s.push(tem->right);
            }

        }

        while( !result.empty()){
            ans.push_back(result.top()->val);
            result.pop();
        }

        return ans;

    }
};
