class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int i=0,n=chalk.size();
        long long sum=0;
        for(int i=0;i<n;i++){
            sum+=chalk[i];
        }

        int div = k/sum;
        int rem = k-(sum*div);
        int ans = -1;

        for(int i=0;i<n;i++){
            if(chalk[i]>rem){
                ans = i;
                break;
            }

            rem-=chalk[i];
        }

        return ans;
    }
};