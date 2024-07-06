class Solution {
public:
    int passThePillow(int n, int time) {
        int d = time/(n-1);
        int m = time%(n-1);

        if(d%2){
            return n-m;
        }else{
            return m+1;
        }
    }
};