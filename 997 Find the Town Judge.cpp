class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int,int>a,b;
        for(int i=0;i<trust.size();i++){
            a[trust[i][0]]+=1;
            b[trust[i][1]]+=1;
        }
        
        for(int i=1;i<=n;i++){
            if(a[i]==0 && b[i]==n-1){
                return i;
            }
        }

        return -1;
    }
};