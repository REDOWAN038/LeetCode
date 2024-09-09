class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        vector<int>pmin(n,-1),pmax(n,-1),nmin(n,n),nmax(n,n);
        stack<int>st;

        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }

            if(!st.empty()){
                pmin[i] = st.top();
            }

            st.push(i);
        }

        st = stack<int>();

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>nums[i]){
                st.pop();
            }

            if(!st.empty()){
                nmin[i] = st.top();
            }

            st.push(i);
        }

        st = stack<int>();

        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]<=nums[i]){
                st.pop();
            }

            if(!st.empty()){
                pmax[i] = st.top();
            }

            st.push(i);
        }

        st = stack<int>();

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<nums[i]){
                st.pop();
            }

            if(!st.empty()){
                nmax[i] = st.top();
            }

            st.push(i);
        }

        long long sum = 0;

        for(int i=0;i<n;i++){
            long long lmin = i-pmin[i];
            long long rmin = nmin[i]-i;
            long long lmax = i-pmax[i];
            long long rmax = nmax[i]-i;

            sum+=(((rmax*lmax)-(rmin*lmin))*nums[i]);
        }

        return sum;
    }
};