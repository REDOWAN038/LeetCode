class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int cnt=0,n=A.size();
        vector<int>C(n),mp(n+1,0);

        for(int i=0;i<n;i++){
            mp[A[i]]++;
            if(mp[A[i]]==2){
                cnt++;
            }

            mp[B[i]]++;
            if(mp[B[i]]==2){
                cnt++;
            }

            C[i] = cnt;
        }

        return C;
    }
};