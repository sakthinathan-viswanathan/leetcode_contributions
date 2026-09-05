/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:



    int recursion(TreeNode* root,int res){

        if(root == nullptr){
            return 0;
        }

         res = res * 10 + root->val;

        if(root->left == nullptr && root->right == nullptr){
            return res;
        }

        int l = recursion(root->left,res);
        int r = recursion(root->right,res);

        return l + r;

    }

    int sumNumbers(TreeNode* root) {
        
      return recursion(root,0);
    }
};