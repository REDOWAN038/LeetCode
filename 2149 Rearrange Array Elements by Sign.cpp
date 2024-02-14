// 1st approach:
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>pos,neg,res;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                pos.push_back(nums[i]);
            }else{
                neg.push_back(nums[i]);
            }
        }

        for(int i=0;i<pos.size();i++){
            res.push_back(pos[i]);
            res.push_back(neg[i]);
        }

        return res;
    }
};

// 2nd approach:
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>res(nums.size());
        int l=0,r=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                res[l] = nums[i];
                l+=2;
            }else{
                res[r] = nums[i];
                r+=2;
            }
        }

        return res;
    }
};
