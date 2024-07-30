class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size(),a=0,b=0,res=n+1;

        for(int i=0;i<n;i++){
            if(s[i]=='a'){
                a++;
            }
        }

        int curr=0;

        for(int i=0;i<n;i++){
            if(s[i]=='a'){
                curr++;
            }

            res = min(res,b+a-curr);

            if(s[i]=='b'){
                b++;
            }
        }

        return res;
    }
};