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
    bool hasPathSum(TreeNode* root, int targetSum) {
        return recursion(root,targetSum,0);
    }

    bool recursion(TreeNode* root,int target,int sum){
        if(root == nullptr){
            return false;
        }
        int tot = sum + root->val;
        if(root->left == nullptr && root->right == nullptr && target == tot){
            return true;
        }

        bool l = recursion(root->left,target,tot);
        bool r = recursion(root->right,target,tot);

        return r || l;
    }
};