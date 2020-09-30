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
    int n , m; 
    while (cin >> n >> m && n+m) {
        set<int>a; 
        for (int i=0,u; i<n; ++i) {
            cin >> u; 
            a.insert(u);
        }
        int counter{};
        for (int i=0,u; i<n; ++i) {
            cin >> u; 
            counter += (a.find(u) != a.end());
        }
        cout << counter << '\n'; 
    }
    return 0;
}
