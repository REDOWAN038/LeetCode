class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxx=0;
        int l=0,r=0,cnt=0;
        
        while(r<nums.size()){
            if(nums[r]==1){
                r++;
                maxx = max(maxx,r-l);
            }else{
                if(k){
                    r++;
                    maxx = max(maxx,r-l);
                    k-=1;
                }else{
                    while(l<r && nums[l]==1){
                        l++;
                    }
                    l++;
                    k++;
                }
            }
        }

        return maxx;
    }
};