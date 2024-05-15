class Solution {
public:
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int,int>>q;
        vector<vector<int>>safety(n, vector<int>(n, INT_MAX));

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    safety[i][j] = 0;
                }
            }
        }

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int xx = x+dx[i];
                int yy = y+dy[i];

                if(xx>=0 && xx<n && yy>=0 && yy<n && safety[xx][yy]>safety[x][y]+1){
                    safety[xx][yy] = safety[x][y]+1;
                    q.push({xx,yy});
                }
            }
        }

        priority_queue<pair<int,pair<int,int>>>pq;
        pq.push({safety[0][0],{0,0}});
        vector<vector<int>>vis(n, vector<int>(n, 0));

        while(!pq.empty()){
            int safeness = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();

            if(i==n-1 && j==n-1){
                return safeness;
            }

            for(int k=0;k<4;k++){
                int ii = i+dx[k];
                int jj = j+dy[k];

                if(ii>=0 && ii<n && jj>=0 && jj<n && !vis[ii][jj]){
                    pq.push({min(safeness,safety[ii][jj]),{ii,jj}});
                    vis[ii][jj] = 1;
                }
            }
        }

        return 0;
    }
};