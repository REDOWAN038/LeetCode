class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int cnt = 1;
        vector<int> curr = points[0];

        for(int i=1;i<points.size();i++){
            if(curr[0]<=points[i][0] && curr[1]>=points[i][0]){
                curr[0] = max(curr[0], points[i][0]);
                curr[1] = min(curr[1],points[i][1]);
            }else{
                cnt+=1;
                curr = points[i];
            }
        }

        return cnt;
    }
};