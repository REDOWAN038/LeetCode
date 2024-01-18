class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int>mp;
        for(int i=0;i<tasks.size();i++){
            mp[tasks[i]]+=1;
        }

        int tot = 0;

        for(auto it:mp){
            if(it.second==1){
                return -1;
            }else if(it.second%3==0){
                tot+=(it.second/3);
            }else{
                tot+=(it.second/3);
                tot+=1;
            }
        }

        return tot;
    }
};