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
        
        vector<int> col(n+1, -1), cnt(2, 0);
        
        function<bool(int, int)> DFS = [&] (int u, int color) {
            if(col[u] == -1) {
                cnt[color]++;
                col[u] = color;
                for(auto v : graph[u]) {
                    if(DFS(v, color ^ 1));
                    else
                        return false;
                }
                return true;
            }
            else {
                return (col[u] == color);
            }
        };
        
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            if(col[i] == -1) {
                cnt[0] = cnt[1] = 0;
                if(DFS(i, 0))
                    ans += max(cnt[0], cnt[1]);
            }
        }
        
        cout << ans << "\n";
    }

    return 0;
}
