class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>freq(26, 0);
        for(int i=0;i<tasks.size();i++){
            freq[tasks[i]-'A']+=1;
        }

        sort(freq.begin(),freq.end());
        int batches = freq[25]-1;
        int vac = batches*n;

        for(int i=24;i>=0;i--){
            vac-=min(batches,freq[i]);
        }

        if(vac<0){
            return tasks.size();
        }else{
            return tasks.size()+vac;
        }
    }
};