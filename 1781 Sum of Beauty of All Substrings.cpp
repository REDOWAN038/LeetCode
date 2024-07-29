class Solution {
public:
    int beautySum(string s) {
        int res = 0;

        for (int i = 0; i < s.size(); i++) {
            map<char, int> mp;
            for (int j = i; j < s.size(); j++) {
                mp[s[j]] += 1;
                int maxx = -1, minn = 1000;
                for (auto it : mp) {
                    maxx = max(maxx, it.second);
                    minn = min(minn, it.second);
                }
                res += (maxx - minn);
            }
        }

        return res;
    }
};