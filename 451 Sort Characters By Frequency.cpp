class Solution {
public:
    static bool cmp(pair<char, int> a, pair<char, int> b) {
        return a.second > b.second;
    }

    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]] += 1;
        }

        vector<pair<char, int>> v;

        for (auto it : mp) {
            v.push_back({it.first, it.second});
        }

        sort(v.begin(), v.end(), cmp);
        string res="";

        for (int i = 0; i < v.size(); i++) {
            for(int j=0;j<v[i].second;j++){
                res+=v[i].first;
            }
        }

        return res;
    }
};