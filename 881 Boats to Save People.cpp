class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int i=0,j=people.size()-1,cnt=0;

        while(i<=j){
            if(i==j){
                cnt+=1;
                break;
            }
            
            if(people[i]+people[j]<=limit){
                i+=1;
                j-=1;
            }else{
                j-=1;
            }
            cnt+=1;
        }

        return cnt;
    }
};