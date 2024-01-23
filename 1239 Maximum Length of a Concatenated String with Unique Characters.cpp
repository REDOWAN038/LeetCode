class Solution {
public:
    int res = 0;
    bool allUnq(string s){
        unordered_set<char>ss;
        for(int i=0;i<s.size();i++){
            ss.insert(s[i]);
        }
        return ss.size()==s.size();
    }

    void getMax(int i,string s,vector<string>&arr){
        if(i>=arr.size()){
            return;
        }

        if(allUnq(s)){
            int sz = s.size();
            res = max(res,sz);
        }else{
            return;
        }

        for(int j=i;j<arr.size();j++){
            getMax(j,s+arr[j],arr);
        } 
    }

    int maxLength(vector<string>& arr) {
        getMax(0,"",arr);
        return res;
    }
};