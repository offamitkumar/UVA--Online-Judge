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
    while(t--){
        long double n; cin >> n;
        cout << (int)((sqrt(1ll + 8ll * n)-1ll) / (long double)2.0f) << '\n'; 
    }
    return 0;
}
