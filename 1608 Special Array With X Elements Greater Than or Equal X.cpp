class Solution {
public:
    int count(vector<int>&nums, int curr){
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=curr){
                cnt+=1;
            }
        }
        return cnt;
    }

    int specialArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int l=0,r=nums.size();

        while(l<=r){
            int mid = l+(r-l)/2;
            int res = count(nums,mid);

            if(mid==res){
                return res;
            }else if(res>mid){
                l = mid+1;
            }else{
                r = mid-1;
            }
        }

        return -1;
    }
};