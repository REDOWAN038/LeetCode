class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;

        for(int i=0;i<num.size();i++){
            char v = num[i];

            while(!st.empty() && k && st.top()>v){
                st.pop();
                k-=1;
            }

            st.push(v);
        }

        while(!st.empty() && k){
            st.pop();
            k-=1;
        }

        string res="";

        while(!st.empty()){
            res+=(st.top());
            st.pop();
        }

        reverse(res.begin(),res.end());

        size_t pos = res.find_first_not_of('0');
        res = (pos == std::string::npos) ? "0" : res.substr(pos);

        return res;
    }
};