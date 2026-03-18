/******************************************************************************

Author: ZoroXD
Date & Time: 18-03-2026 11:51:03

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tt;
    cin >> tt;
    while(tt--) {
        int n, m;
        cin >> n >> m;
        
        vector<vector<int>> graph(n+1);
        for(int i = 1; i <= m; i++)
        {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        bool ok = true;
        vector<int> dist(n+1, -1), cnt(2, 0);
        
        function<void(int, int, int)> DFS = [&] (int u, int prev, int d) {
            if(dist[u] == -1) {
                cnt[d&1]++;
                dist[u] = d;
                for(auto v : graph[u]) {
                    DFS(v, u, d + 1);
                }
            }
            else if(abs(dist[u] - dist[prev]) % 2 == 0) {
                ok = false;
            }
        };
        
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            if(dist[i] == -1) {
                cnt[0] = cnt[1] = 0;
                DFS(i, i, 0);
                if(ok)
                    ans += max(cnt[0], cnt[1]);
                ok = true;
            }
        }
        
        cout << ans << "\n";
    }

    return 0;
}
