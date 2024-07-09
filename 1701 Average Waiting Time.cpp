class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double sum=0,curr=0;
        for(int i=0;i<customers.size();i++){
            int a = customers[i][0];
            int b = customers[i][1];

            if(curr<a){
                curr = a;
            }

            curr+=b;

            sum+=(curr-a);
        }

        return sum/customers.size();
    }
};