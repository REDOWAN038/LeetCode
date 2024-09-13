class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int>xors(n);
        xors[0]=arr[0];
        for(int i=1;i<n;i++){
            xors[i] = xors[i-1]^arr[i];
        }

        vector<int>res;

        for(int i=0;i<queries.size();i++){
            if(queries[i][0]==0){
                res.push_back(xors[queries[i][1]]);
            }else{
                int temp = xors[queries[i][1]]^xors[queries[i][0]-1];
                res.push_back(temp);
            }
        }

        return res;
    }
};