class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        vector<int> res;

        for(int i=0;i<s.size();i++){
            int cnt=0;
            int r = startPos[0];
            int c = startPos[1];
            for(int j=i;j<s.size();j++){
                if(s[j]=='U'){
                    r-=1;
                }else if(s[j]=='D'){
                    r+=1;
                }else if(s[j]=='R'){
                    c+=1;
                }else{
                    c-=1;
                }

                if(r>=0 && c>=0 && r<=n-1 && c<=n-1){
                    cnt+=1;
                }else{
                    break;
                }
            }
            res.push_back(cnt);
        }

        return res;
    }
};