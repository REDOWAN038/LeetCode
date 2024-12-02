class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int n=sentence.size();
        int m = searchWord.size();
        int i=0,cnt=1;

        while(i<n){
            int j=0;

            while(sentence[i]==searchWord[j] && i<n && j<m){
                i++;
                j++;
            }

            if(j==m){
                return cnt;
            }

            while(sentence[i]!=' ' && i<n){
                i++;
            }
            i++;
            cnt++;
        }

        return -1;
    }
};