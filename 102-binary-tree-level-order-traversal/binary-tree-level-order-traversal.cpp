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
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>>res;

        if(root == nullptr){
            return res;
        }

        queue<TreeNode*>que;

        que.push(root);


        while(!que.empty()){

            int n = que.size();
            vector<int>cur;

            for(int i=0;i<n;i++){
                TreeNode* node = que.front();
                que.pop();

                cur.push_back(node->val);

                if(node->left != nullptr){
                    que.push(node->left);
                }


                if(node->right != nullptr){
                    que.push(node->right);
                }
            }

            res.push_back(cur);
        }

        return res;
        
    }
};