class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> sortedScore = score;
        sort(sortedScore.rbegin(), sortedScore.rend());
        vector<string> ranks = {"Gold Medal", "Silver Medal", "Bronze Medal"};
        map<int, string> mp;
        for (int i = 0; i < sortedScore.size(); i++) {
            if (i < 3) {
                mp[sortedScore[i]] = ranks[i];
            } else {
                mp[sortedScore[i]] = to_string(i + 1);
            }
        }
        vector<string> ans;
        for (auto value : score) {
            ans.push_back(mp[value]);
        }

        return ans;
    }
};