class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n=asteroids.size();
        stack<int>st;
        int i;

        for(i=n-1;i>=0;i--){
            if(asteroids[i]>0){
                while(!st.empty() && st.top()<0 && abs(st.top())<asteroids[i]){
                    st.pop();
                }

                if(!st.empty() && st.top()<0 && abs(st.top())==asteroids[i]){
                    st.pop();
                }else if(st.empty() || st.top()>0){
                    st.push(asteroids[i]);
                }
            }else{
                st.push(asteroids[i]);
            }
        }

        vector<int>res;

        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }

        return res;
    }
};