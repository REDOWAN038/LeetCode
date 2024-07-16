class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1=0,cnt2=0;
        int el1=-1,el2=-1;

        for(int i=0;i<nums.size();i++){
            int v = nums[i];
            if(cnt1==0 && v!=el2){
                cnt1=1;
                el1=v;
            }else if(cnt2==0 && v!=el1){
                cnt2=1;
                el2=v;
            }else if(v==el1){
                cnt1+=1;
            }else if(v==el2){
                cnt2+=1;
            }else{
                cnt1-=1;
                cnt2-=1;
            }
        }

        vector<int>res;

        int th=nums.size()/3;
        cnt1=0,cnt2=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]==el1){
                cnt1+=1;
            }else if(nums[i]==el2){
                cnt2+=1;
            }
        }

        if(cnt1>th){
            res.push_back(el1);
        }

        if(cnt2>th){
            res.push_back(el2);
        }

        return res;
    }
};