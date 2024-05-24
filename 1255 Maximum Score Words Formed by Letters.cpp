class Solution {
public:
    unordered_map<char,int>mp;

    bool isValid(string s){
        unordered_map<char,int>tmp;
        for(int i=0;i<s.size();i++){
            tmp[s[i]]+=1;
        }
        for(int i=0;i<s.size();i++){
            if(tmp[s[i]]>mp[s[i]]){
                return false;
            }
        }
        return true;
    }

    void removeChar(string s){
        for(int i=0;i<s.size();i++){
            mp[s[i]]-=1;
        }
    }

    void addChar(string s){
        for(int i=0;i<s.size();i++){
            mp[s[i]]+=1;
        }
    }

    int calcSum(string s, vector<int>&score){
        int sum=0;
        for(int i=0;i<s.size();i++){
            sum+=score[s[i]-'a'];
        }
        return sum;
    }

    int backtrack(int idx, vector<string>& words, vector<int>& score){
        if(idx==words.size()){
            return 0;
        }

        int res = backtrack(idx+1,words,score);

        if(isValid(words[idx])){
            removeChar(words[idx]);
            res = max(res, calcSum(words[idx], score)+backtrack(idx+1,words,score));
            addChar(words[idx]);
        }
        return res;
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        for(int i=0;i<letters.size();i++){
            mp[letters[i]]+=1;
        }
        return backtrack(0, words, score);
    }
};