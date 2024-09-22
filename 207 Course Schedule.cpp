class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        map<int,int>indeg;
        vector<vector<int>>v(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            int f = prerequisites[i][0];
            int s = prerequisites[i][1];
            indeg[f]++;
            v[s].push_back(f);
        }
        
        queue<int>q;
        int cnt=0;
        
        for(int i=0;i<numCourses;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;
            
            for(int it:v[node]){
                indeg[it]--;
                if(indeg[it]==0){
                    q.push(it);
                }
            }
        }
        
        return cnt==numCourses?true:false;
    }
};