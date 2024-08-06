class Solution {
public:
    int minimumPushes(string word) {
        vector<int>freq(26,0);
        int tot=0;

        for(int i=0;i<word.size();i++){
            freq[word[i]-'a']+=1;
        }

        sort(freq.rbegin(),freq.rend());

        for(int i=0;i<26;i++){
            if(freq[i]==0){
                break;
            }

            tot+=(i/8+1)*freq[i];
        }

        return tot;
    }
};