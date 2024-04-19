class Solution {
public:
    bool vis[350][350];

    void dfs(int i,int j,int n,int m,vector<vector<char>>& grid){
        if(i<0 || j<0 || i>=n || j>=m || vis[i][j] || grid[i][j]=='0'){
            return;
        }

        vis[i][j] = true;
        dfs(i+1,j,n,m,grid);
        dfs(i-1,j,n,m,grid);
        dfs(i,j+1,n,m,grid);
        dfs(i,j-1,n,m,grid);
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    dfs(i,j,n,m,grid);
                    cnt+=1;
                }
            }
        }

        return cnt;
    }
};