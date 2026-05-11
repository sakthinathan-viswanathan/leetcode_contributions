class Solution {
public:

    int dfs(int r, int c,
            vector<vector<int>>& dp,
            vector<vector<int>>& matrix) {

        if (dp[r][c] != 0)
            return dp[r][c];

        int n = matrix.size();
        int m = matrix[0].size();

        vector<pair<int,int>> dir = {
            {0,1}, {1,0}, {0,-1}, {-1,0}
        };

        int ans = 1;

        for (auto [i, j] : dir) {

            int nr = r + i;
            int nc = c + j;

            if (nr < 0 || nr >= n ||
                nc < 0 || nc >= m)
                continue;

            if (matrix[nr][nc] > matrix[r][c]) {

                ans = max(ans,
                          1 + dfs(nr, nc, dp, matrix));
            }
        }

        return dp[r][c] = ans;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 0));

        int max_ele = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                max_ele = max(max_ele,
                              dfs(i, j, dp, matrix));
            }
        }

        return max_ele;
    }
};