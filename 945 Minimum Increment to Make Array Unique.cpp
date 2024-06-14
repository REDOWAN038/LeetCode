// 1st approach
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        std::sort(nums.begin(),nums.end());
        int cnt=0,n=nums.size();

        for(int i=1;i<n;i++){
            if(nums[i]<=nums[i-1]){
                int inc = nums[i-1]-nums[i]+1;
                cnt+=inc;
                nums[i] = nums[i-1]+1;
            }
        }

        return cnt;
    }
};


// 2nd approach
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int cnt=0,n=nums.size();
        int maxx = *max_element(nums.begin(),nums.end());

        vector<int>v(n+maxx+1,0);

        for(int i:nums){
            v[i]+=1;
        }

        for(int i=0;i<v.size();i++){
            if(v[i]<=1){
                continue;
            }

            int d = v[i]-1;
            cnt+=d;
            v[i+1]+=d;
            v[i] = 1;
        }

        return cnt;
    }
};