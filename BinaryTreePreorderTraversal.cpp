/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include<iostream>
#include<vector>
using namespace std;
#include<stack>
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
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

int main(){
	TreeNode *root = new TreeNode(1);
	root -> left = new TreeNode(4);
	TreeNode *right = new TreeNode(3);
	right -> left = new TreeNode(2);
	root -> right = right;
	vector<int> tem = preorderTraversal(root);
	for (int i = 0; i < tem.size(); i ++){
		cout<<tem[i]<<endl;
	}

	return 0;
}
