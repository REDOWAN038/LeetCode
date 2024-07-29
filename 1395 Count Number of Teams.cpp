class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size(), res=0;

        for(int i=0;i<n;i++){
            int c1=0,c2=0,c3=0,c4=0;

            for(int j=i-1;j>=0;j--){
                if(rating[j]<rating[i]){
                    c1+=1;
                }
                if(rating[j]>rating[i]){
                    c2+=1;
                }
            }

            for(int j=i+1;j<n;j++){
                if(rating[j]>rating[i]){
                    c3+=1;
                }
                if(rating[j]<rating[i]){
                    c4+=1;
                }
            }

            res+=((c1*c3)+(c2*c4));
        } 

        return res;       
    }
};