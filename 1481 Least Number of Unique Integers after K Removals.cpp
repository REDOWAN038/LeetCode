class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int>mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]+=1;
        }

        vector<int>v;

        for(auto it:mp){
            v.push_back(it.second);
        }

        sort(v.begin(),v.end());
        int cnt=v.size();
        int i=0;

        while(k && i<v.size()){
            if(v[i]<=k){
                k-=v[i];
                cnt-=1;
                i++;
            }else{
                break;
            }
        }

        return cnt;
    }
};