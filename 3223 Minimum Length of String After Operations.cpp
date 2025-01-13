class Solution {
public:
    int minimumLength(string s) {
        vector<int>freq(26,0);
        int cnt=0;

        for(char c:s){
            freq[c-'a']++;
        }

        for(int val:freq){
            if(val==0){
                continue;
            }

            if(val%2){
                cnt+=1;
            }else{
                cnt+=2;
            }
        }

        return cnt;
    }
};