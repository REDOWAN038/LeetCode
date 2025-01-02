class Solution {
public:
    bool vowelString(string s){
        int n = s.size();
        unordered_set<char>vowels{'a','e','i','o','u'};

        if(vowels.count(s[0]) && vowels.count(s[n-1])){
            return true;
        }

        return false;
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int>pre(n+1,0);

        for(int i=0;i<n;i++){
            if(vowelString(words[i])){
                pre[i+1] = pre[i]+1;
            }else{
                pre[i+1] = pre[i];
            }
        }

        int m = queries.size();
        vector<int>ans(m,0);

        for(int i=0;i<m;i++){
            int u = queries[i][0];
            int v = queries[i][1];
            ans[i] = pre[v+1]-pre[u];
        }

        return ans;
    }
};