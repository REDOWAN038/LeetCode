class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int r = heights.size();
        int c = heights[0].size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        int dist[r][c];

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                dist[i][j] = 1e9;
            }
        }

        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};
        dist[0][0] = 0;
        pq.push({0,0,0});

        while(!pq.empty()){
            vector<int>v = pq.top();
            pq.pop();

            for(int i=0;i<4;i++){
                int x = v[1]+dx[i];
                int y = v[2]+dy[i];

                if(x>=0 && x<r && y>=0 && y<c){
                    int maxx = max(dist[v[1]][v[2]],abs(heights[x][y]-heights[v[1]][v[2]]));
                    if(maxx<dist[x][y]){
                        dist[x][y] = maxx;
                        pq.push({maxx,x,y});
                    }
                }
            }
        }

        return dist[r-1][c-1];
    }
};