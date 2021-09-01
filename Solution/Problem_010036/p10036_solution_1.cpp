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
        set<int>s; 
        int n,k; cin >> n >> k; 
        int x; cin >> x; 
        s.insert(x%k);
        for(int i=1; i<n; ++i) {
            cin >> x; 
            set<int>T; 
            for (auto&itr:s) {
                T.insert((itr+x)%k); 
                T.insert((itr-x)%k);
            }
            s = T; 
        }
        bool ans = false; 
        for (auto&itr: s) {
            ans |= (itr%k==0);
        }
        if (ans) {
            cout << "Divisible" << '\n'; 
        } else {
            cout << "Not divisible" << '\n'; 
        }
    }
    return 0;
}
