class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int cnt=0,n=grid.size(),m=grid[0].size();
        queue<pair<int,int>>q;
        bool vis[n][m];
        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,-1,1};

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                vis[i][j] = false;
                if(grid[i][j]==1){
                    cnt++;
                }

                if(i==0 || i==n-1 || j==0 || j==m-1){
                    if(grid[i][j]==1){
                        vis[i][j] = true;
                        q.push({i,j});
                        cnt--;
                    }
                }
            }
        }

        while(!q.empty()){
            pair<int,int>curr = q.front();
            q.pop();

            for(int i=0;i<4;i++){
                int x = curr.first+dx[i];
                int y = curr.second+dy[i];

                if(x>=0 && x<n && y>=0 && y<m && grid[x][y]==1 && !vis[x][y]){
                    vis[x][y] = true;
                    cnt--;
                    q.push({x,y});
                }
            }
        }

        return cnt;
    }
};