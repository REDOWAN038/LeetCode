class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int sum = 0;
        int mod = 1e9+7;
        int n = arr.size();

        vector<int>v1(n),v2(n);
        stack<int>s1,s2;

        for(int i=0;i<n;i++){
            v1[i] = n-i-1;
            v2[i] = i;
        }

        for(int i=0;i<n;i++){
            while(!s1.empty() && arr[s1.top()]>arr[i]){
                v1[s1.top()] = i-s1.top()-1;
                s1.pop();
            }
            s1.push(i);
        }

        for(int i=n-1;i>=0;i--){
            while(!s2.empty() && arr[s2.top()]>=arr[i]){
                v2[s2.top()] = s2.top()-i-1;
                s2.pop();
            }
            s2.push(i);
        }

        for(int i=0;i<n;i++){
            long long cnt = (v1[i]+1)*(v2[i]+1);
            long long temp = (arr[i]*cnt)%mod;
            sum+=temp;
            sum%=mod;
        }

        return sum;
    }
};