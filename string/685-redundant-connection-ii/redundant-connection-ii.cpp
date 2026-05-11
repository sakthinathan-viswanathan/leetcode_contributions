class Solution {
public:
    vector<int> parent;

    int findParent(int node) {
        if (parent[node] != node) {
            parent[node] = findParent(parent[node]);
        }

        return parent[node];
    }

    bool unionSet(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);

        if (pu == pv) {
            return false; 
        }

        parent[pv] = pu;

        return true;
    }

    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {

        int n = edges.size();

        vector<int> indegree(n + 1, -1);

        vector<int> candidate1, candidate2;

        for (int i = 0; i < n; i++) {

            int u = edges[i][0];
            int v = edges[i][1];

            if (indegree[v] == -1) {
                indegree[v] = i;
            }
            else {

                candidate1 = edges[indegree[v]];
                candidate2 = edges[i];

                edges[i][1] = 0;
            }
        }

        parent.resize(n + 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }

        for (auto &edge : edges) {

            int u = edge[0];
            int v = edge[1];

            if (v == 0)
                continue;

            if (!unionSet(u, v)) {

                if (candidate1.empty()) {
                    return edge;
                }

                
                return candidate1;
            }
        }

       
        return candidate2;
    }
};