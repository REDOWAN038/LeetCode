class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        std::unordered_map<int,int>mp;
        int maxx=0,sum=0;

        for(int i:nums){
            mp[i]+=1;
            maxx = std::max(maxx,mp[i]);
        }

        for(auto it:mp){
            if(it.second==maxx){
                sum+=it.second;
            }
        }

        return sum;
    }
};