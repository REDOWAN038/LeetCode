class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int left=1,right=1,maxx=INT_MIN,n=nums.size();

        for(int i=0;i<n;i++){
            left*=nums[i];
            right*=nums[n-i-1];
            maxx = max(maxx,max(left,right));
            if(left==0){
                left=1;
            }
            if(right==0){
                right=1;
            }
        }

        return maxx;
    }
};