class Solution {
public:
    int partitionString(string s) {
        int cnt=1;
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])==mp.end()){
                mp[s[i]]+=1;
            }else{
                cnt+=1;
                mp.clear();
                mp[s[i]]+=1;
            }
        }

        return cnt;
    }
};