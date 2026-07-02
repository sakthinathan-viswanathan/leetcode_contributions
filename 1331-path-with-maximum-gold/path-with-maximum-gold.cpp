class Solution {
public:

    int solve(int r,int c,vector<vector<int>> &grid){

        int n = grid.size();
        int m = grid[0].size();

        if(r < 0 || r >= n || c < 0 || c >= m || grid[r][c] == 0){
            return 0;
        }

        int vis = grid[r][c];

        grid[r][c] = 0;

        int res =   max({solve(r+1,c,grid) ,
                    solve(r-1,c,grid) ,
                    solve(r,c+1,grid) ,
                    solve(r,c-1,grid)}) ;

        grid[r][c] = vis;
        //cout<<"res "<<res<<" vis "<<vis<<endl;

        return res + vis;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        
        int n = grid.size();

        int m  = grid[0].size();

        int res = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(grid[i][j] != 0){
                    //cout<<"grid "<<grid[i][j]<<endl;
                    res = max(res,solve(i,j,grid));
                }

            }
        }

        return res;
    }
};