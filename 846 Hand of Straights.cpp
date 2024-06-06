class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize){
            return false;
        }

        map<int,int>mp;

        for(int i:hand){
            mp[i]+=1;
        }

        for(auto it:mp){
            int j = it.first;
            int val = it.second;

            if(val){
                for(int i=0;i<groupSize;i++){
                if(mp[i+j]<val){
                    return false;
                }
                mp[i+j]-=val;
            }
            }
        }

        return true;
    }
};