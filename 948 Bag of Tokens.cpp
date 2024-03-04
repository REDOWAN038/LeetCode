class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int n = tokens.size();
        int l=0,r=n-1,curr=0,maxx=0;

        while(l<=r){
            if(power>=tokens[l]){
                curr+=1;
                power-=tokens[l];
                l+=1;
                maxx = max(maxx,curr);
            }else if(curr>0){
                curr-=1;
                power+=tokens[r];
                r-=1;
            }else{
                break;
            }
        }

        return maxx;
    }
};