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

    TreeNode* recursion(TreeNode* root,int data){

         if(root == nullptr || root->val == data){
            return root;
        }

        if(data < root->val){
            return recursion(root->left, data);
        }

        return recursion(root->right, data);

    }
    TreeNode* searchBST(TreeNode* root, int data) {
        return recursion(root,data);
    }
};