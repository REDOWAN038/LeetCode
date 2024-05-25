class Solution {
public:
    vector<string>res;

    bool isValid(int idx,string s1,string s2){
        int sz = s1.size()-idx;

        if(sz<s2.size()){
            return false;
        }

        for(int i=0,j=idx;i<s2.size() && j<s1.size();i++,j++){
            if(s2[i]!=s1[j]){
                return false;
            }
        }

        return true;
    }

    void backtrack(int idx,string curr,string s,vector<string>&wordDict){
        if(idx>=s.size()){
            curr.pop_back();
            res.push_back(curr);
        }

        for(int i=0;i<wordDict.size();i++){
            if(isValid(idx,s,wordDict[i])){
                string tmp = curr+wordDict[i]+" ";
                backtrack(idx+wordDict[i].size(),tmp,s,wordDict);
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        backtrack(0,"",s,wordDict);
        return res;
    }
};