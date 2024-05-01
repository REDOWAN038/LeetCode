class Solution {
public:
    string reversePrefix(string word, char ch) {
        int idx=-1;

        for(int i=0;i<word.size();i++){
            if(word[i]==ch){
                idx=i;
                break;
            }
        }

        if(idx==-1){
            return word;
        }

        string res=word;

        for(int j=0,i=idx;i>=0;i--,j++){
            res[j] = word[i];
        }

        return res;
    }
};