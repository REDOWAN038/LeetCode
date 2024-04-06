class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char,int>>st;

        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push({'(',i});
            }else if(s[i]==')'){
                if(!st.empty()){
                    auto curr = st.top();
                    if(curr.first=='('){
                        st.pop();
                    }else{
                        st.push({')',i});
                    }
                }else{
                    st.push({')',i});
                }
            }
        }

        while(!st.empty()){
            auto cur = st.top();
            st.pop();
            s.erase(cur.second, 1);
        }

        return s;
    }
};