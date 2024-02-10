class Solution {
public:
    string palindrome(int i,int j,string s){
        while(i>=0 && j<s.size() && s[i]==s[j]){
            i-=1;
            j+=1;
        }
        return s.substr(i+1,j-i-1);
    }
    string longestPalindrome(string s) {
        int maxx=0;
        string res;

        for(int i=0;i<s.size();i++){
            string curr =  palindrome(i,i,s);
            if(curr.size()>maxx){
                maxx = curr.size();
                res = curr;
            }

            if(i+1<s.size()){
                curr = palindrome(i,i+1,s);
                if(curr.size()>maxx){
                    maxx = curr.size();
                    res = curr;
                }
            }
        }

        return res;
    }
};