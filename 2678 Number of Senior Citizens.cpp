class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt=0;

        for(int i=0;i<details.size();i++){
            string s = details[i];
            int age = ((s[11]-'0')*10)+(s[12]-'0');

            if(age>60){
                cnt+=1;
            }
        }

        return cnt;
    }
};