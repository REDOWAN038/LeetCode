class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>res;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int i=0,j=0,prev=-1;

        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]<nums2[j]){
                i+=1;
            }else if(nums1[i]>nums2[j]){
                j+=1;
            }else{
                if(nums1[i]!=prev){
                    res.push_back(nums1[i]);
                    prev = nums1[i];
                }
                i+=1;
                j+=1;
            }
        }

        return res;
    }
};