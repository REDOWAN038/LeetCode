class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int stc = image[sr][sc];

        if(stc==color){
            return image;
        }
        
        image[sr][sc] = color;
        queue<pair<int,int>>q;
        q.push({sr,sc});
        int n = image.size();
        int m = image[0].size();

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        while(!q.empty()){
            pair<int,int> curr = q.front();
            q.pop();

            for(int i=0;i<4;i++){
                int x = curr.first + dx[i];
                int y = curr.second + dy[i];

                if(x>=0 && x<n && y>=0 && y<m && image[x][y]==stc){
                    q.push({x,y});
                    image[x][y] = color;
                }
            }
        }

        return image;
    }
};