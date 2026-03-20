/******************************************************************************

Author: ZoroXD
Date & Time: 20-03-2026 16:44:33

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main()
{
    int tt;
    cin >> tt;
    while(tt--) {
        string s;
        cin >> s;
        
        vector<int> cnt(10, 0);
        for(char c : s) cnt[c-'0']++;
        
        function<void(int, vector<int>&)> digitAdder = [&] (int num, vector<int> &vec) {
            int x = 0, t = num;
            while(num) {
                int r = num%10;
                vec[r]++;
                x+=r;
                num/=10;
            }
            
            if(x == t) return;
            else digitAdder(x, vec);
        };
        
        function<void(string)> print = [&] (string s) {
            if(s.length() == 1) {
                cout << s << "\n";
                return;
            }
            
            int x = stoi(s), y = 0;
            while(x) {
                int r = x % 10;
                y += r;
                cout << r;
                x/= 10;
            }
            
            print(to_string(y));
        };
        
        int k = s.length();
        for(int sum = 1; sum <= 9 * 1e5; sum++) {
            vector<int> vec(10, 0);
            digitAdder(sum, vec);
            
            int val = 0;
            bool ok = true;
            for(int i = 0; i < 10; i++) {
                val += max(0LL, (cnt[i] - vec[i])) * i;
                ok |= vec[i] <= cnt[i];
            }
            
            if(ok && val == sum) {
                for(int i = 9; i >= 0; i--) {
                    for(int j = 1; j <= (cnt[i] - vec[i]); j++)
                        cout << i;
                }
                print(to_string(sum));
            }
        }
    }

    return 0;
}
