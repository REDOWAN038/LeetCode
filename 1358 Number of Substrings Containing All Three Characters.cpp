class Solution {
public:
    int numberOfSubstrings(string s) {
        int l=0, r=0, res=0, n= s.size() ;
        unordered_map<char, int> mp ;
        
        while(r < n){
            mp[s[r]]++ ;
            
            while(mp['a']  &&  mp['b']  &&  mp['c']){
                res++;
                res+=(n-r-1);
                
                mp[s[l]]-- ;
                l++ ;
            }
            
            r++ ;
        }
        
        return res ;
    }
};