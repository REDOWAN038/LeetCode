class Solution {
public:
    vector<vector<char>> rotate(vector<vector<char>>& box){
        int n = box.size();
        int m = box[0].size();
        vector<vector<char>>newBox(m,vector<char>(n,'.'));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                newBox[j][n-i-1] = box[i][j];
            }
        }

        return newBox;
    }

    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n = box.size();
        int m = box[0].size();

        for(int i=0;i<n;i++){
            int k=m-1;
            for(int j=m-1;j>=0;j--){
                if(box[i][j]=='#'){
                    box[i][j] = '.';
                    box[i][k] = '#';
                    k--;
                }else if(box[i][j]=='*'){
                    k = j-1;
                }
            }
        }

        return rotate(box);
    }
};