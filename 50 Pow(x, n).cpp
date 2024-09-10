class Solution {
public:
    double myPow(double x, int n) {
        if(n<0){
            x = 1/x;
        }

        long num = labs(n);
        double res = 1;

        while(num){
            if(num&1){
                res*=x;
                num--;
            }else{
                x*=x;
                num/=2;
            }
        }

        return res;
    }
};