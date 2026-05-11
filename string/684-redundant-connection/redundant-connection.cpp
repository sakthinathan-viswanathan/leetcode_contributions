class Solution {
public:

    vector<int>parent;

    int findParent(int u){

        if(parent[u] != u){
            parent[u] = findParent(parent[u]);
        }

        return parent[u];
    }

    bool unionSet(int u,int v){

        int pu  = findParent(u);
        int pv = findParent(v);

        if(pu == pv){
            return false; //cycle dected
        }

        parent[pv] = pu;

        return true;


    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size();
        parent.resize(n+1);

        for(int i=0;i<n;i++){
            parent[i] = i;
        }

        for(auto& edge:edges){

            if(!unionSet(edge[0],edge[1])){
                return  edge;
            }
        }

        return {};


        
    }
};