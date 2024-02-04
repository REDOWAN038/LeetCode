class Solution {
public:
    string minWindow(string s, string t) {
        if(s.empty() || t.empty() || s.size()<t.size()){
            return "";
        }
        
        unordered_map<char,int>mp;
        for(int i=0;i<t.size();i++){
            mp[t[i]]+=1;
        }

        int l=0,r=0,cnt=mp.size(),st=0,len=INT_MAX;

        while(r<s.size()){
            mp[s[r]]-=1;
            if(mp[s[r]]==0){
                cnt-=1;
            }

            while(cnt==0){
                if((r-l+1)<len){
                    len = r-l+1;
                    st = l;
                }

                if(mp.find(s[l])!=mp.end()){
                    mp[s[l]]+=1;
                    if(mp[s[l]]>0){
                        cnt+=1;
                    }
                }
                l+=1;
            }
            r+=1;
        }

        if(len==INT_MAX){
            return "";
        }else{
            return s.substr(st,len);
        }
    }
};