class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxx=0;
        for(int i=0;i<26;i++){
            int l=0,r=0,kk=k;
            char c = 'A'+i;

            while(r<s.size()){
                if(s[r]==c){
                    r++;
                    maxx = max(maxx,r-l);
                }else{
                    if(kk){
                        r++;
                        maxx = max(maxx,r-l);
                        kk-=1;
                    }else{
                        while(l<r && s[l]==c){
                            l++;
                        }
                        l++;
                        kk++;
                    }
                }
            }
        }

        return maxx;
    }
};