class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]] += 1;
        }

        vector<pair<int,char>> v;

        for (auto it : mp) {
            v.push_back({it.second,it.first});
        }

        sort(v.rbegin(), v.rend());
        string res="";

        for (int i = 0; i < v.size(); i++) {
            for(int j=0;j<v[i].first;j++){
                res+=v[i].second;
            }
        }

        return res;
    }
};
