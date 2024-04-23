class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0};
        vector<int> res,adj[n],degree(n);

        for(auto i : edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);

            degree[i[0]]++;
            degree[i[1]]++;
        }

        queue<int> q;
        for(int i =0; i<n; i++)
            if(degree[i]==1) 
                q.push(i);

        int leftNodes = n;            
        while(!q.empty()){
            int sz = q.size();
            leftNodes -= sz;
            while(sz--){
                int currNode = q.front();
                q.pop();

                if(leftNodes == 0)
                    res.push_back(currNode);

                for(int adjNode : adj[currNode]){
                    if(--degree[adjNode]==1){
                        q.push(adjNode);
                    }
                }
            }
        }

        return res;
    }
};