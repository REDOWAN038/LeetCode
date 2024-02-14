class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> res(nums.size());
        int l = 0, r = nums.size() - 1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < pivot) {
                res[l++] = nums[i];
            }
        }
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (nums[i] > pivot) {
                res[r--] = nums[i];
            }
            else if (nums[i] == pivot) {
                res[l++] = nums[i];
            }
        }
        return res;
    }
};