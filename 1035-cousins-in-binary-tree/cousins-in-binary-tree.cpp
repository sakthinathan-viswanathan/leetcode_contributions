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

    TreeNode* parentx = nullptr;
    TreeNode* parenty = nullptr;

    int depthx = -1;
    int depthy = -1;

    void recursion(TreeNode* root,TreeNode* parent,int depth,int x,int y){
        if(root == nullptr){
            return ;
        }

       if(root->val == x){
        parentx = parent;
        depthx = depth;
       }

       if(root->val == y){
        parenty = parent;
        depthy = depth;
       }

       recursion(root->left,root,depth+1,x,y);
       recursion(root->right,root,depth+1,x,y);

    }
    

    bool isCousins(TreeNode* root, int x, int y) {
        
        recursion(root,nullptr,0,x,y);

        return (depthx == depthy) && (parentx != parenty);
    }
};