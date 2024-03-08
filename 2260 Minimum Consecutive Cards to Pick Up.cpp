class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int,int>mp;
        int minn = INT_MAX;

        for(int i=0;i<cards.size();i++){
            if(mp[cards[i]]){
                minn = std::min(minn,i-mp[cards[i]]+2);
                mp[cards[i]] = i+1;
            }else{
                mp[cards[i]] = i+1;
            }
        }

        return minn==INT_MAX ? -1 : minn;
    }
};