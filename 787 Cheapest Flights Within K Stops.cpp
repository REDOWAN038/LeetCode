class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        map<int,vector<pair<int,int>>>adj;

        for(int i=0;i<flights.size();i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }

        vector<int>dist(n, INT_MAX);
        dist[src] = 0;

        queue<pair<int,int>>q;
        q.push({src,0});
        int cnt=0;

        while(!q.empty() && cnt<=k){
            int sz = q.size();

            while(sz--){
                pair<int,int> cur = q.front();
                q.pop();

                if(!adj[cur.first].size()){
                    continue;
                }

                for(int i=0;i<adj[cur.first].size();i++){
                    if(cur.second+adj[cur.first][i].second < dist[adj[cur.first][i].first]){
                        dist[adj[cur.first][i].first] = cur.second+adj[cur.first][i].second;
                        q.push({adj[cur.first][i].first, dist[adj[cur.first][i].first]});
                    }
                }
            }
            cnt+=1;
        }

        return dist[dst]==INT_MAX ? -1 : dist[dst];
    }
};