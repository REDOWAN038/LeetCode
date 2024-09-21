class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int cnt = 0, tot = 0, days = 0;
        int n = grid.size(), m = grid[0].size();
        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,-1,1};

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                if(grid[i][j]!=0){
                    tot++;
                }
            }
        }

        while(!q.empty()){
            int sz = q.size();
            cnt+=sz;
            bool ck = false;

            while(sz--){
                pair<int,int> curr = q.front();
                q.pop();

                for(int i=0;i<4;i++){
                    int x = curr.first+dx[i];
                    int y = curr.second+dy[i];

                    if(x>=0 && x<n && y>=0 && y<m && grid[x][y]==1){
                        ck = true;
                        grid[x][y] = 2;
                        q.push({x,y});
                    }
                }
            }

            if(ck){
                days++;
            }
        }

        return tot==cnt ? days : -1;

    }
};