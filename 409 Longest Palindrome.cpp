class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>mp;
        int cnt=0;

        for(int i=0;i<s.size();i++){
            mp[s[i]]+=1;
            if(mp[s[i]]%2){
                cnt+=1;
            }else{
                cnt-=1;
            }
        }

        if(cnt){
            return s.size()-cnt+1;
        }else{
            return s.size();
        }
    }
};