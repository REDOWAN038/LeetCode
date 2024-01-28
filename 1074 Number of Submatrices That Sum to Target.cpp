class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(),m=matrix[0].size(),res=0;

        for(int c1=0;c1<m;c1++){
            vector<int>preSum(n, 0);
            for(int c2=c1;c2<m;c2++){
                for(int i=0;i<n;i++){
                    preSum[i]+=matrix[i][c2];
                }
                for(int r1=0;r1<n;r1++){
                    int sum=0;
                    for(int r2=r1;r2<n;r2++){
                        sum+=preSum[r2];
                        if(sum==target){
                            res+=1;
                        }
                    }
                }
            }
        }

        return res;
    }
};