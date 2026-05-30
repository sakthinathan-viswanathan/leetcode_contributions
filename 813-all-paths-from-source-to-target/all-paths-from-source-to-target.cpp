class Solution {
public:

    void dfs(int node,vector<int>path,vector<vector<int>>& res,vector<vector<int>>& graph){

        int target = graph.size()-1;

        if(node == target){
            res.push_back(path);
            return ;
        }

        for(int nei:graph[node]){
            path.push_back(nei);
            dfs(nei,path,res,graph);
            path.pop_back();
        }

        return;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {

        vector<vector<int>>res;

        vector<int>path = {0};

        dfs(0,path,res,graph);

        return res;
        
    }
};