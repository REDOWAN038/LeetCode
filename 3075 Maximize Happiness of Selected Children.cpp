class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), greater<int>());
        
        long long res = 0;
        int cnt = 0;
        
        for(int i = 0; i < k; i++) {
            res += max(happiness[i] - cnt, 0);  
            cnt++; 
        }
        
        return res;
    }
};