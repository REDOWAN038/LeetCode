// 1st approach
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        unordered_map<char, int> mp1;
        for (int i = 0; i < words[0].size(); i++) {
            mp1[words[0][i]] += 1;
        }

        for (int i = 1; i < words.size(); i++) {
            unordered_map<char, int> mp2;
            for (int j = 0; j < words[i].size(); j++) {
                mp2[words[i][j]] += 1;
            }

            for (auto it : mp1) {
                char c = it.first;
                int v = it.second;
                mp1[c] = min(v, mp2[c]);
            }
        }

        vector<string> res;

        for (int i = 0; i < words[0].size(); i++) {
            if (mp1[words[0][i]]) {
                string s = "";
                s += words[0][i];
                res.push_back(s);
                mp1[words[0][i]]-=1;
            }
        }

        return res;
    }
};

// 2nd approach
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string>res;

        for(char ch='a';ch<='z';ch++){
            int minn = INT_MAX;

            for(string word:words){
                int cnt=0;
                for(char c:word){
                    if(c==ch){
                        cnt+=1;
                    }
                }
                minn = min(minn,cnt);
            }

            for(int i=0;i<minn;i++){
                string s = "";
                s+=ch;
                res.push_back(s);
            }
        }

        return res;
    }
};