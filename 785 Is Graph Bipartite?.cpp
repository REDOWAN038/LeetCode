class Solution {
public:
    map<int,int>mp;

    bool bfs(int src,vector<vector<int>>& graph){
        mp[src] = 1;
        queue<int>q;
        q.push(src);

        while(!q.empty()){
            int curr = q.front();
            q.pop();

            for(int i=0;i<graph[curr].size();i++){
                int node = graph[curr][i];

                if(mp[node]==mp[curr]){
                    return false;
                }else if(!mp[node]){
                    if(mp[curr]==1){
                        mp[node] = 2;
                    }else{
                        mp[node] = 1;
                    }
                    q.push(node);
                }
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        for(int i=0;i<n;i++){
            if(!mp[i]){
                if(!bfs(i, graph)){
                    return false;
                }
            }
        }

        return true;
    }
};