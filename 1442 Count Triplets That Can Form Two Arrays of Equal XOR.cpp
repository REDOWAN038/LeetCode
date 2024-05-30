// 1st approach
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int cnt=0;

        for(int i=0;i<arr.size()-1;i++){
            int a = 0;
            for(int j=i+1;j<arr.size();j++){
                a^=arr[j-1];
                int b = 0;
                for(int k=j;k<arr.size();k++){
                    b^=arr[k];
                    if(a==b){
                        cnt+=1;
                    }
                }
            }
        }

        return cnt;
    }
};


// 2nd approach
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int cnt=0;

        for(int i=0;i<arr.size()-1;i++){
            int curr=arr[i];
            for(int k=i+1;k<arr.size();k++){
                curr^=arr[k];
                if(curr==0){
                    cnt+=(k-i);
                }
            }
        }

        return cnt;
    }
};