class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();

        if(n!=m){
            return false;
        }

        vector<int>v(26,0);

        for(int i=0;i<n;i++){
            v[s[i]-'a']+=1;
            v[t[i]-'a']-=1;
        }

        for(int i=0;i<v.size();i++){
            if(v[i]){
                return false;
            }
        }

        return true;
    }
};