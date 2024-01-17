class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        long long sum=0;
        int maxx = 0;
        for(int i=0;i<milestones.size();i++){
            sum+=milestones[i];
            maxx = max(maxx,milestones[i]);
        }

        if(maxx==(sum-maxx)){
            return (2*(sum-maxx));
        }else if(maxx>(sum-maxx)){
            return (2*(sum-maxx))+1;
        }else{
            return sum;
        }
    }
};