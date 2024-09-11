class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int maxx = 0;
        map<char,int>mp;
        int l=0,r=0;

        while(r<n){
            if(!mp[s[r]]){
                mp[s[r]]+=1;
                r+=1;
                maxx = max(maxx,r-l);
            }else{
                while(l<r && s[l]!=s[r]){
                    mp[s[l]]-=1;
                    l+=1;
                }

                mp[s[l]]-=1;
                l+=1;
            }
        }

        return maxx;
    }
};