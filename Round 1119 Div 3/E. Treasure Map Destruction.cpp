#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int tt;
    cin >> tt;
    while(tt--) 
    {
        int n;
        cin >> n;
        
        vector<int> a(n);
        for(auto &i : a) cin >> i;
        
        vector<int> sweep(n+1);
        for(int i = 0; i < n; i++) {
            if(a[i] > 0)
            {
                sweep[max(0, i - a[i] + 1)] += 1;
                sweep[min(n, i + a[i])] -=1 ;
            }
        }
        
        for(int i = 1; i <= n; i++) sweep[i] += sweep[i-1];
        
        string ans(n, '1');
        for(int i = 0; i < n; i++) {
            if(sweep[i] > 0)
                ans[i] = '0';
        }
        
        bool ok = 1;
        for(int i = 0; i < n; i++)
        {
            bool isSafe = 0;
            if(a[i] > 0 && ((i - a[i] >= 0 && ans[i-a[i]] == '1') || (i + a[i] < n && ans[i + a[i]] == '1')))
                isSafe = 1;
            if(a[i] < 1) {
                isSafe = 1;
                if(a[i] == 0 && ans[i] != '1')
                    isSafe = 0;
            }
            ok &= isSafe;
        }
        
        if(!ok) cout << -1 << "\n";
        else cout << ans << "\n";
    }

    return 0;
}
