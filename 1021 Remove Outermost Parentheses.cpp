class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt=0;
        string res="";

        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                if(cnt){
                    res+=s[i];
                }
                cnt+=1;
            }else{
                cnt-=1;
                if(cnt){
                    res+=s[i];
                }
            }
        }

        return res;
    }
};