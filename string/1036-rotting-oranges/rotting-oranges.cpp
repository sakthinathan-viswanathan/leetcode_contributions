class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        int fresh = 0;

        queue<pair<int,int>>que;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    que.push({i,j});
                }
                else if(grid[i][j] == 1)
                    fresh++;
            
            }
        }

        vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};

        int mi = 0;

        while(!que.empty() && fresh > 0){

            int num = que.size();

            for(int i=0;i<num;i++){

                int x = que.front().first;
                int y = que.front().second;
                que.pop();

                for(auto &[a,b]:dir){
                    int nx = x+a;
                    int ny = y+b;

                    if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1){
                        grid[nx][ny] = 2;
                        fresh--;
                        que.push({nx,ny});
                    }
                }
            }

            mi++;
        }

        return fresh == 0?mi:-1;
    
        
    }
};