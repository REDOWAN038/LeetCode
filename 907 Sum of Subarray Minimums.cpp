class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int mod = 1e9+7;
        vector<int>v1(n,-1),v2(n,n);
        stack<int>st;

        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }

            if(!st.empty()){
                v1[i] = st.top();
            }

            st.push(i);
        }

        st = stack<int>();

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }

            if(!st.empty()){
                v2[i] = st.top();
            }

            st.push(i);
        }

        int sum = 0;

        for(int i=0;i<n;i++){
            long long p = (i-v1[i])*(v2[i]-i);
            long long q = (p*arr[i])%mod;
            sum = (sum+q)%mod;
        }

        return sum;
    }
};