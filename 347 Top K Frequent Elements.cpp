class Solution {
public:
    static bool cmp(pair<int,int>a, pair<int,int>b){
        return a.second>b.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]+=1;
        }

        vector<pair<int,int>>v;

        for(auto it : mp){
            v.push_back({it.first,it.second});
        }

        sort(v.begin(),v.end(),cmp);
        vector<int>res;

        for(int i=0;i<k;i++){
            res.push_back(v[i].first);
        }

        return res;
    }
};