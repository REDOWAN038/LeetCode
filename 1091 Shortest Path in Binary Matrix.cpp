class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if(grid[0][0]==1 || grid[n-1][n-1]==1){
            return -1;
        }

        if(n==1){
            return 1;
        }

        queue<pair<int,int>>q;
        int dx[] = {0,-1,-1,-1,0,1,1,1};
        int dy[] = {-1,-1,0,1,1,1,0,-1};

        q.push({0,0});
        int lvl = 0;

        while(!q.empty()){
            int sz = q.size();
            lvl++;

            while(sz--){
                pair<int,int>curr = q.front();
                q.pop();

                if(curr.first==n-1 && curr.second==n-1){
                    return lvl;
                }

                for(int i=0;i<8;i++){
                    int x = curr.first+dx[i];
                    int y = curr.second+dy[i];

                    if(x>=0 && x<n && y>=0 && y<n && grid[x][y]==0){
                        grid[x][y] = 1;
                        q.push({x,y});
                    }
                }
            }
        }

        return -1;
    }
};