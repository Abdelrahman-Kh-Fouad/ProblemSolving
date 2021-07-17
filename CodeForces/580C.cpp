    #include <bits/stdc++.h>
    using namespace std;
    int m;
    vector<bool> used;
    int dfs(vector<vector<int>> &adj, vector<int> &nodes, int node, int cur)
    {
     
        used[node] = 1;
        if (cur > m)
            return 0;
        int res = 0;
        int cnt = 0;
        ;
        for (auto i : adj[node])
        {
            int next = 0;
            if (cur && nodes[i])
                next += cur + nodes[i];
            else
                next += nodes[i];
            if (!used[i])
                res += dfs(adj, nodes, i, next);
            cnt++;
        }
        if (adj[node].size() - 1 == 0 && node != 0)
            res += 1;
        return res;
    }
    int main()
    {
        int n;
        cin >> n >> m;
        used.assign(n, 0);
        vector<int> nodes(n);
        for (int i = 0; i < n; i++)
            cin >> nodes[i];
        vector<vector<int>> adj(n);
        int from, to;
        for (int i = 0; i < n - 1; i++)
        {
            cin >> from >> to;
            if (from > to)
                swap(from, to);
            adj[from - 1].push_back(to - 1);
            adj[to - 1].push_back(from - 1);
        }
        cout << dfs(adj, nodes, 0, nodes[0]) << endl;
    }