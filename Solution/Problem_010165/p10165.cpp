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
    int n;
    while (cin >> n , n) {
        int sum{};
        for (int i=0,x=0; i<n; ++i) {
            cin >> x; 
            sum ^= x;
        }
        cout << (sum?"Yes":"No") << '\n'; 
    }
    return 0;
}
