class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());

        vector<vector<int>>ans;

        for(int i= 0;i<points.size();i++) {
            if(ans.empty()){
                ans.push_back(points[i]);
            }
            else if(points[i][0] > ans.back()[1]){
                ans.push_back(points[i]);
            }
            else{
                ans.back()[1] = min(points[i][1], ans.back()[1]);
            }
        }
        return ans.size();
    }
};