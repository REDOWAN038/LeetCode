class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int>res;
        map<int,int>mp;

        for(int i:arr1){
            mp[i]+=1;
        }

        for(int i:arr2){
            for(int j=0;j<mp[i];j++){
                res.push_back(i);
            }
            mp[i]=0;
        }

        for(auto it:mp){
            for(int i=0;i<it.second;i++){
                res.push_back(it.first);
            }
        }

        return res;
    }
};