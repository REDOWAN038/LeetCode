class Solution {
public:
    int maxDepth(string s) {
        int cnt=0,maxx=0;

        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                cnt+=1;
                maxx = max(maxx, cnt);
            }else if(s[i]==')'){
                cnt-=1;
            }
        }

        return maxx;
    }
};