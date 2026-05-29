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
    int max_sum = INT_MIN;

int recursion(TreeNode* root){
    if(root == nullptr){
        return 0;
    }

    int  l  = max(0,recursion(root->left));
    int r = max(0,recursion(root->right));

    max_sum = max(max_sum,root->val + l + r);

    return root->val + max(l,r);
}

    int maxPathSum(TreeNode* root) {
        recursion(root);

        return max_sum;
    }
};