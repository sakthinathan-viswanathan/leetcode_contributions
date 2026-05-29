class Solution {
public:

    vector<tuple<int,int,int>> adj;

    void dfs(TreeNode* root, int row, int col) {

        if (root == nullptr) {
            return;
        }

        adj.push_back({col, row, root->val});

        dfs(root->left, row + 1, col - 1);

        dfs(root->right, row + 1, col + 1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {

        dfs(root, 0, 0);

        
        sort(adj.begin(), adj.end());

        vector<vector<int>> res;

        int precol = INT_MIN;

        for (auto& [col, row, val] : adj) {

            if (col != precol) {
                res.push_back({});
                precol = col;
            }

            res.back().push_back(val);
        }

        return res;
    }
};