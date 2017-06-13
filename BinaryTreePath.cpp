/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void findPath(TreeNode *root, vector<string> &path, string temp){
        if (root == nullptr){
            return;
        }
        int num = root->val;
        bool flag = true;
        if (num < 0){
            flag = false;
            num *= -1;
        }
        string tnum = "";
        while (num){
            int t1 = num % 10;
            char dig = t1 + '0';
            tnum = (dig) + tnum;
            num = num / 10;
        }
        if (!flag){
            temp += "-";
        }
        if (root->left == nullptr && root->right == nullptr){
            temp += tnum;
            path.push_back(temp);
            return ;
        }
        else{
            
            temp += tnum;
            temp += "->";
        }
        findPath(root->left, path, temp);
        findPath(root->right, path, temp);
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if (root == nullptr){
            return result;
        }
        findPath(root, result, "");
        return result;
    }
};
