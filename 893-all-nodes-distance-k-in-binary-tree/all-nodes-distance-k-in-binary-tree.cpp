/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        unordered_map<TreeNode*,TreeNode*>parent;

        queue<TreeNode*>que;
        que.push(root);

        while(!que.empty()){

            TreeNode* node = que.front();

            que.pop();

            if(node->left != nullptr){
                parent[node->left] = node;
                que.push(node->left);
            }

            if(node->right != nullptr){
                parent[node->right] = node;

                que.push(node->right);
            }
        }

        unordered_set<TreeNode*>visited;
        visited.insert(target);

        que.push(target);

        int dis = 0;

        while(!que.empty()){

            int n = que.size();
            
            if(dis == k){
                break;
            }

            for(int i=0;i<n;i++){
                
                TreeNode* node = que.front();
                que.pop();

                if(node->left && !visited.count(node->left)){
                    visited.insert(node->left);

                    que.push(node->left);
                }

                if(node->right && !visited.count(node->right))
                {
                    visited.insert(node->right);
                    que.push(node->right);
                }

                if(parent[node] && !visited.count(parent[node])){
                    visited.insert(parent[node]);
                    que.push(parent[node]);
                }

            }

            dis++;
        }

        vector<int>res;

        while(!que.empty()){
            res.push_back(que.front()->val);
            que.pop();
        }

        return res;
        
    }
};