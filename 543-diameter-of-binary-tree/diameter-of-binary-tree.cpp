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
    int diameter = 0;
    int recursion(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }

        int l = recursion(root->left);
        int r = recursion(root->right);

        diameter = max(diameter,l+r);

        return max(l,r) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root){
        recursion(root);

        return diameter;

    }
};