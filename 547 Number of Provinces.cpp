class Solution {
public:
    map<int,bool>vis;

    void dfs(int node, vector<vector<int>>& isConnected){
        if(vis[node]){
            return;
        }

        vis[node] = true;

        for(int i=0;i<isConnected[node].size();i++){
            if(!vis[i] && isConnected[node][i]==1){
                dfs(i, isConnected);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int cnt = 0;

        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,isConnected);
            }
        }

        return cnt;
    }
};