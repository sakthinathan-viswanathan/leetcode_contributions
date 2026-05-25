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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
            TreeNode* nn = new TreeNode(val);

            if(root == nullptr){
                root = nn;
                return root;
            }

            TreeNode* temp = root;

            while(true){

                if(temp->val > val){
                    if(temp->left == nullptr){
                        temp->left = nn;
                        return root;
                    }

                    temp = temp->left;
                }
                else
                {
                    if(temp->right == nullptr){
                        temp->right = nn;
                        return root;
                    }

                    temp = temp->right;
                }
            }


            return root;

        
    }
};