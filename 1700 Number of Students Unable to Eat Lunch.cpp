class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        stack<int> sd;
        queue<int> st;
        int count=0;
        for(int i=0;i<students.size();i++){
               st.push(students[i]);
        }
        for(int i=sandwiches.size()-1;i>=0;i--){
               sd.push(sandwiches[i]);
        }
        while(!st.empty()){
            if(st.front()==sd.top()){
                st.pop();
                sd.pop();
            }
            else{
                int temp=st.front();
                st.pop();
                st.push(temp);
            }
            count++;
            if(count==300) break;
        }
        return st.size();
    }
};