class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>prev(n,-1),next(n,n);
        stack<int>st;

        for(int i=0;i<n;i++){
            while(!st.empty() && heights[i]<=heights[st.top()]){
                st.pop();
            }

            if(!st.empty()){
                prev[i] = st.top();
            }

            st.push(i);
        }

        st = stack<int>();

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[i]<heights[st.top()]){
                st.pop();
            }

            if(!st.empty()){
                next[i] = st.top();
            }

            st.push(i);
        }

        int maxx = 0;

        for(int i=0;i<n;i++){
            int w = next[i]-prev[i]-1;
            int area = w*heights[i];
            maxx = max(maxx,area);
        }

        return maxx;
    }
};