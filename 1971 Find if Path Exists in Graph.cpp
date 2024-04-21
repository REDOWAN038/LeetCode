class Solution {
public:
    map<int,bool>vis;

    void dfs(int src,int dest,vector<vector<int>>&v){
        if(vis[dest]){
            return;
        }

        vis[src] = true;

        for(int i=0;i<v[src].size();i++){
            if(!vis[v[src][i]]){
                dfs(v[src][i],dest,v);
            }
        }
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>v(n);
        for(int i=0;i<edges.size();i++){
            int x = edges[i][0];
            int y = edges[i][1];
            v[x].push_back(y);
            v[y].push_back(x);
        }

        dfs(source,destination,v);
        return vis[destination];
    }
};