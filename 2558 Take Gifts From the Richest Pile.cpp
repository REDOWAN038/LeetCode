class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int>pq;

        for(int i=0;i<gifts.size();i++){
            pq.push(gifts[i]);
        }

        while(k--){
            int curr = pq.top();
            pq.pop();
            int root = sqrt(curr);
            pq.push(root);
        }

        long long sum=0;

        while(!pq.empty()){
            sum+=pq.top();
            pq.pop();
        }

        return sum;
    }
};