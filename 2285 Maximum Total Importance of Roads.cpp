class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int>deg(n,0);

        for(int i=0;i<roads.size();i++){
            deg[roads[i][0]]+=1;
            deg[roads[i][1]]+=1;
        }

        sort(deg.begin(),deg.end());
        long long curr=1,res=0;

        for(int i=0;i<n;i++){
            res+=(deg[i]*curr);
            curr+=1;
        }

        return res;
    }
};