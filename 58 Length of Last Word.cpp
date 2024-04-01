class Solution {
public:
    int lengthOfLastWord(string s) {
        int cnt=0,res=0;

        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                if(cnt!=0){
                    res=cnt;
                    cnt=0;
                }
            }else{
                cnt+=1;
            }
        }

        if(cnt!=0){
            res=cnt;
        }

        return res;
    }
};