class Solution {
public:
    string reverseWords(string s) {
        vector<string>v;
        string temp="";
        for(int i=0;i<s.size();i++){
            if(s[i]!=' '){
                temp+=s[i];
            }else{
                if(temp.size()){
                    v.push_back(temp);
                }
                temp="";
            }
        }

        if(temp.size()){
            v.push_back(temp);
            temp="";
        }

        int i;

        for(i=v.size()-1;i>=1;i--){
            temp+=v[i];
            temp+=" ";
        }
        temp+=v[i];

        return temp;
    }
};