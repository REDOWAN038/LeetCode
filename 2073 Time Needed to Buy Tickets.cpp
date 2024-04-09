// 1st approach : 

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        deque<int>dq;
        int cnt=0;
        for(int i=0;i<tickets.size();i++){
            dq.push_back(i);
        }

        while(!dq.empty()){
            cnt+=1;
            int curr = dq.front();
            dq.pop_front();
            tickets[curr]-=1;
        
            if(curr==k && tickets[curr]==0){
                return cnt;
            }

            if(tickets[curr]>0){
                dq.push_back(curr);
            }
        }

        return 0;
    }
};

// 2nd approach : 

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int cnt = 0;
        while(tickets[k]!=0){
            for(int i = 0; i<tickets.size(); i++){
                if(tickets[k]==0) break;
                if(tickets[i]==0) continue;
                else{
                    tickets[i]--;
                    cnt++;
                }
            }
        }
        return cnt;
    }
};