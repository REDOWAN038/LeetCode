class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        if(k==n)return "0";

        string result = "";
        result.push_back(num[0]);

        int i=1; 
        while(i<n){
            char ch = num[i];
            if(ch >= result.back())result.push_back(ch);
            else{
                while(!result.empty() && result.back() > ch && k != 0){
                result.pop_back();
                k--;
                }
                result.push_back(ch);
            }
            i++;    
        }
        if(k != 0){

            while(!result.empty() && k--){
                result.pop_back();
            }

        }

        i=0;
        while(i<result.size() && result[i] == '0')i++;

        if(i>= result.size())return "0";
        
        string ans = "";
        while(i<result.size()){
            ans.push_back(result[i]);
            i++;
        }
        return ans;
    }
};