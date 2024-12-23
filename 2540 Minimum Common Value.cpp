class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int i=0,j=0;

        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]==nums2[j]){
                return nums1[i];
            }else if(nums1[i]<nums2[j]){
                i+=1;
            }else{
                j+=1;
            }
        }

        return -1;
    }
};