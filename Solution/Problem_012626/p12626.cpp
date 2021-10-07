#include <bits/stdc++.h>
using namespace std;
#define int int64_t

signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    int t; cin >> t; 
    while (t--) {
        string s; cin >> s; 
        map<char,int>m;
        for (auto&i:s) {
            m[i]++; 
        }
        int ans{INT_MAX}; 
        ans = min(ans, m['M']); 
        ans = min(ans, m['A']/3); 
        ans = min(ans, m['R']/2); 
        ans = min(ans, m['G']); 
        ans = min(ans, m['I']); 
        ans = min(ans, m['T']); 
        cout << ans << '\n'; 
    }
    return 0;
}
