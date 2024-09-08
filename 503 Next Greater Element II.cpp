class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n-1;i++){
            nums.push_back(nums[i]);
        }

        stack<int>st;
        vector<int> v,res;
        int m = nums.size();

        for(int i=m-1;i>=0;i--){
            int val = nums[i];

            while(!st.empty() && st.top()<=val){
                st.pop();
            }

            if(st.empty()){
                v.push_back(-1);
            }else{
                v.push_back(st.top());
            }

            st.push(val);
        }

        for(int i=m-1;i>=(m-n);i--){
            res.push_back(v[i]);
        }

        return res;
    }
};