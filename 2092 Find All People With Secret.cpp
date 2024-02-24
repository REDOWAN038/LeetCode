class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        map<int, vector<pair<int, int> > > mp;
        vector<bool> mp1(n);
        for(int i=0;i<meetings.size();i++){
            mp[meetings[i][2]].push_back({meetings[i][0],meetings[i][1]});
        }

        mp1[0] = mp1[firstPerson] = true;

        for(auto it=mp.begin();it!=mp.end();it++){
            vector<pair<int,int> > v = it->second;
            int curr = it->first;

            unordered_map<int,vector<int> > adj;
            set<int>st;

            for(int i=0;i<v.size();i++){
                adj[v[i].first].push_back(v[i].second);
                adj[v[i].second].push_back(v[i].first);
                if(mp1[v[i].first]){
                    st.insert(v[i].first);
                }
                if(mp1[v[i].second]){
                    st.insert(v[i].second);
                }
            }

            queue<int>q;
            for(auto& val:st){
                q.push(val);
            }

            while(!q.empty()){
                int node = q.front();
                q.pop();
                for(int i=0;i<adj[node].size();i++){
                    if(!mp1[adj[node][i]]){
                        mp1[adj[node][i]] = true;
                        q.push(adj[node][i]);
                    }
                }
            }
        }

        vector<int>res;

            for(int i=0;i<n;i++){
                if(mp1[i]){
                    res.push_back(i);
                }
            }

            return res;
    }
};