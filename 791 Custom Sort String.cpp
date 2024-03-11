class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int>mp;
        unordered_map<char,bool>mp1;
        string res = "";
        
        for(int i=0;i<s.size();i++){
            mp[s[i]]+=1;
        }

        for(int i=0;i<order.size();i++){
            int n = mp[order[i]];
            mp1[order[i]] = true;
            for(int j=0;j<n;j++){
                res+=order[i];
            }
        }

        for(auto it:mp){
            if(!mp1[it.first]){
                int n = it.second;
                for(int i=0;i<n;i++){
                    res+=(it.first);
                }
            }
        }

        return res;
    }
};