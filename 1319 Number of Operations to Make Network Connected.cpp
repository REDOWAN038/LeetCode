class Solution {
public:
    map<int,int>par,sz;

    int findPar(int u){
        if(u==par[u]){
            return u;
        }

        return par[u] = findPar(par[u]);
    }

    void unionBySize(int u,int v){
        if(sz[u]<sz[v]){
            sz[v]+=sz[u];
            par[u] = v;
        }else{
            sz[u]+=sz[v];
            par[v] = u;
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        for(int i=0;i<n;i++){
            par[i] = i;
            sz[i] = 1;
        }

        int ext=0,cnt=0;

        for(int i=0;i<connections.size();i++){
            int u = connections[i][0];
            int v = connections[i][1];

            int pu = findPar(u);
            int pv = findPar(v);

            if(pu==pv){
                ext++;
            }else{
                unionBySize(pu,pv);
            }
        }

        for(int i=0;i<n;i++){
            if(i==par[i]){
                cnt++;
            }
        }

        cnt--;

        if(ext>=cnt){
            return cnt;
        }else{
            return -1;
        }
    }
};