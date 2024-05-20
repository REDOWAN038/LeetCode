// 1st approach
class Solution {
public:
    int calcXor(vector<int>& nums, int i, int curr){
        if(i>=nums.size()){
            return curr;
        }

        return (calcXor(nums, i+1, curr^nums[i]) + calcXor(nums, i+1, curr));
    }

    int subsetXORSum(vector<int>& nums) {
        return calcXor(nums, 0, 0);
    }
};

// 2nd approach (efficient)
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int res=0;

        for(int i=0;i<n;i++){
            res|=nums[i];
        }

        return (res<<(n-1));
    }
};