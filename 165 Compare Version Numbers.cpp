class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i=0,j=0,sz1=version1.size(),sz2=version2.size();

        while(i<sz1 && j<sz2){
            int num1=0,num2=0;

            while(i<sz1 && version1[i]!='.'){
                num1 = num1*10 + (version1[i]-'0');
                i++;
            }

            while(j<sz2 && version2[j]!='.'){
                num2 = num2*10 + (version2[j]-'0');
                j++;
            }

            if(num1<num2){
                return -1;
            }

            if(num1>num2){
                return 1;
            }

            i++;
            j++;
        }

        while(i<sz1){
            int num1=0;

            while(i<sz1 && version1[i]!='.'){
                num1 = num1*10 + (version1[i]-'0');
                i++;
            }

            if(num1>0){
                return 1;
            }

            i++;
        }

        while(j<sz2){
            int num2=0;

            while(j<sz2 && version2[j]!='.'){
                num2 = num2*10 + (version2[j]-'0');
                j++;
            }

            if(num2>0){
                return -1;
            }

            j++;
        }

        return 0;
    }
};