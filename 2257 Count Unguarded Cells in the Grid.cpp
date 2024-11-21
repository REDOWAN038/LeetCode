class Solution {
public:
    void markGuarded(int x,int y,int m,int n,vector<vector<int>>& graph){
        for(int i=x+1;i<m;i++){
            if(graph[i][y]==1 || graph[i][y]==2){
                break;
            }
            graph[i][y] = 3;
        }

        for(int i=x-1;i>=0;i--){
            if(graph[i][y]==1 || graph[i][y]==2){
                break;
            }
            graph[i][y] = 3;
        }

        for(int i=y+1;i<n;i++){
            if(graph[x][i]==1 || graph[x][i]==2){
                break;
            }
            graph[x][i] = 3;
        }

        for(int i=y-1;i>=0;i--){
            if(graph[x][i]==1 || graph[x][i]==2){
                break;
            }
            graph[x][i] = 3;
        }
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> graph(m, vector<int>(n, 0));

        for(int i=0;i<guards.size();i++){
            int x = guards[i][0];
            int y = guards[i][1];
            graph[x][y] = 1;
        }

        for(int i=0;i<walls.size();i++){
            int x = walls[i][0];
            int y = walls[i][1];
            graph[x][y] = 2;
        }

        for(int i=0;i<guards.size();i++){
            int x = guards[i][0];
            int y = guards[i][1];
            markGuarded(x,y,m,n,graph);
        }

        int cnt=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(graph[i][j]==0){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};