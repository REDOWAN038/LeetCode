class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum=0;
        int minn=INT_MAX,cnt=0;

        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                sum+=abs(matrix[i][j]);
                minn = min(minn,abs(matrix[i][j]));
                if(matrix[i][j]<0){
                    cnt++;
                }
            }
        }

        if(cnt%2){
            return sum-(2*minn);
        }else{
            return sum;
        }
    }
};