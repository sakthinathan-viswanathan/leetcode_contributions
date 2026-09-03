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
    TreeNode* invertTree(TreeNode* root) {
        
        return recursion(root);
    }

    TreeNode* recursion(TreeNode* root){

        if(root == nullptr){
            return nullptr;
        }

        swap(root->left,root->right);

        TreeNode* l = recursion(root->left);

        TreeNode* r = recursion(root->right);

        return root;
    }
};