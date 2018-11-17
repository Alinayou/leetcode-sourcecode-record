class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts)
    {
        // 1. 對於每個 email 建立所在 position 數組
        unordered_map<string, deque<int>> m;
        vector<vector<string>> res;
        for (int i = 0; i < accounts.size(); i++)
        {
            for (int j = 1; j < accounts[i].size(); j++)
            {
                m[accounts[i][j]].push_back(i);
            }
        }
        // 2. "vector<int> visited" 紀錄是否有 traverse 過該 position
        vector<int> visited(accounts.size(), false);
        for (auto it = m.begin(); it != m.end(); it++)
        {
            // "queue<int> q" 紀錄某 email 的 position 以及其在同位置中其他 email的 sub position
            queue<int> q(it->second);
            set<string> s{ it->first };
            int first = q.front();
            if (visited[first])
                continue;
            while (!q.empty())
            {
                int index = q.front();
                q.pop();
                visited[index] = true;
                for (int i = 1; i < accounts[index].size(); i++)
                {
                    string mail = accounts[index][i];
                    s.insert(mail);
                    for (int j = 0; j < m[mail].size(); j++)
                        if (!visited[m[mail][j]])
                        {
                            q.push(m[mail][j]); 
                            visited[m[mail][j]] = true;
                        }
                }
            }
            res.push_back(vector<string>{s.begin(), s.end()});
            res.back().insert(res.back().begin(), accounts[first][0]);
        }
        return res;
    }
};
