// 1st approach
class Solution {
public:
    string plusOne(string s){
        int n = s.size(), c = 1;

        s[n - 1] = '0';

        for (int i = n - 2; i >= 0 && c; i--) {
            if (c && s[i] == '0') {
                s[i] = '1';
                c = 0;
                break;
            } else if (c && s[i] == '1') {
                s[i] = '0';
                c = 1;
            }
        }

        if (c) {
            s = "1" + s;
        }

        return s;
    }

    int numSteps(string s) {
        int cnt=0;
        while(1){
            if(s.size()==1 && s[0]=='1'){
                break;
            }

            int n = s.size();

            if(s[n-1]=='1'){
                s = plusOne(s);
            }else{
                s.pop_back();
            }
            cnt+=1;
        }

        return cnt;
    }
};


// 2nd approach
class Solution {
public:
    int numSteps(string s) {
        int n = s.size();

        int cnt=0,c=0;

        for (int i = n - 1; i > 0; i--) {
            if (((s[i] - '0') + c) % 2) {
                cnt += 2;
                c = 1;
            } else {
                cnt++;
            }
        }

        return cnt + c;
    }
};