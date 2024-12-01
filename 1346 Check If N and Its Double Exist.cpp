class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        map<int,bool>mp;
        for(int i=0;i<arr.size();i++){
            int v = arr[i];

            if(mp[2*v]){
                return true;
            }

            if(v%2==0 && mp[v/2]){
                return true;
            }

            mp[v] = true;
        }

        return false;
    }
};