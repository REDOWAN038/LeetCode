class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp1,mp2;

        for(int i=0;i<arr.size();i++){
            mp1[arr[i]]+=1;
        }

        for(auto it:mp1){
            if(mp2[it.second]){
                return false;
            }else{
                mp2[it.second]+=1;
            }
        }

        return true;
    }
};