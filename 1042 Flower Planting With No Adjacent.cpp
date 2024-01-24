class Solution {
public:
    void bfs(int idx, vector<int>* graph, vector<int>& res) {
        res[idx] = 1;
        queue<int> q;
        q.push(idx);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int x : graph[u]) {
                if (!res[x] || res[x] == res[u]) {
                    res[x] = res[u] + 1;
                    q.push(x);
                }
                if (res[x] > 4) {
                    res[x] %= 4;
                }
            }
        }
    }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> graph[n + 1];

        for (int i = 0; i < paths.size(); i++) {
            graph[paths[i][0]].push_back(paths[i][1]);
            graph[paths[i][1]].push_back(paths[i][0]);
        }

        vector<int> res(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            if (!res[i]) {
                bfs(i, graph, res);
            }
        }
        res.erase(res.begin());
        res.resize(n);
        return res;
    }
};