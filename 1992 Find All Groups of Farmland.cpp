class Solution {
public:
    int maxx,maxy;
    bool vis[310][310];

    void dfs(int i,int j,int n,int m,vector<vector<int>>& land){
        if(i<0 || j<0 || i>=n || j>=m || vis[i][j] || land[i][j]==0){
            return;
        }

        vis[i][j] = true;

        if(land[i][j]==1){
            maxx = max(maxx,i);
            maxy = max(maxy,j);
        }

        dfs(i+1,j,n,m,land);
        dfs(i-1,j,n,m,land);
        dfs(i,j+1,n,m,land);
        dfs(i,j-1,n,m,land);
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n=land.size(),m=land[0].size();
        vector<vector<int>>res;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(land[i][j]==1 && !vis[i][j]){
                    maxx=-1,maxy=-1;
                    dfs(i,j,n,m,land);
                    res.push_back({i,j,maxx,maxy});
                }
            }
        }

        return res;
    }
};