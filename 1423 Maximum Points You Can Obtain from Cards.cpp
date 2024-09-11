class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = 0;
        for(int num:cardPoints){
            sum+=num;
        }

        int n = cardPoints.size();
        int sz = n-k;
        int curr=0;

        for(int i=0;i<sz;i++){
            curr+=cardPoints[i];
        }

        int maxx = sum-curr;
        int l=0,r=sz;
        while(r<n){
            curr-=cardPoints[l];
            curr+=cardPoints[r];
            maxx = max(maxx,sum-curr);
            l+=1;
            r+=1;
        }

        return maxx;
    }
};