class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string>s(wordList.begin(),wordList.end());
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        s.erase(beginWord);

        while(!q.empty()){
            string word = q.front().first;
            int cnt = q.front().second;
            q.pop();

            if(word==endWord){
                return cnt;
            }

            for(int i=0;i<word.size();i++){
                char org = word[i];

                for(char c='a';c<='z';c++){
                    word[i] = c;
                    if(s.find(word)!=s.end()){
                        q.push({word,cnt+1});
                        s.erase(word);
                    }
                }

                word[i] = org;
            }
        }

        return 0;
    }
};