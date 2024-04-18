class Solution {
public:
    bool dfs(int i,int j,int idx,vector<vector<char>>& board, string word){
        if(idx==word.size()){
            return true;
        }

        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || word[idx]!=board[i][j]){
            return false;
        }

        char temp = board[i][j];
        board[i][j] = ' ';

        bool ans = dfs(i-1,j,idx+1,board,word) || 
                   dfs(i+1,j,idx+1,board,word) ||
                   dfs(i,j-1,idx+1,board,word) ||
                   dfs(i,j+1,idx+1,board,word);

        board[i][j] = temp;
        return ans;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0] && dfs(i, j, 0, board, word)){
                    return true;
                }
            }
        }

        return false;
    }
};