class Solution {
public:
    int getSumDiv(vector<int>& nums, int div) {
        int n = nums.size(); 
        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum += ceil((double)(nums[i]) / (double)(div));
        }

        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1, h = *max_element(nums.begin(), nums.end());
        int ans;

        while (l <= h) {
            int mid = (l + h) / 2;
            int sum = getSumDiv(nums, mid);

            if(sum<=threshold){
                ans=mid;
                h=mid-1;
            }else{
                l=mid+1;
            }
        }

        return ans;
    }
};