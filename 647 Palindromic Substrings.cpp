class Solution {
public:
    int palindrome(int i,int j,string s){
        int cnt = 0;
        while(i>=0 && j<s.size() && s[i]==s[j]){
            cnt+=1;
            i-=1;
            j+=1;
        }
        return cnt;
    }

    int countSubstrings(string s) {
        int ans = 0;

        for(int i=0;i<s.size();i++){
            ans+=palindrome(i,i,s);
            if(i+1<s.size()){
                ans+=palindrome(i,i+1,s);
            }
        }

        return ans;
    }
};