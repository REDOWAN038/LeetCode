class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        vector<int>v(n,0);

        for(int i=0;i<s.size();i++){
            v[i] = abs(s[i]-t[i]);
        }

        int cnt=0,i=0,j=0,tot=0;

        while(j<s.size()){
            tot+=v[j];
            if(tot<=maxCost){
                cnt = max(cnt,j-i+1);
            }else{
                tot-=v[i];
                i++;
            }
            j++;
        }

        return cnt;
    }
};