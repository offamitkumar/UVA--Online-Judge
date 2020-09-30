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
        int a,b,c; cin >> a >> b >> c; 
        int bottle = a+b; 
        int counter{}; 
        while (bottle >= c) {
            int newB = (bottle/c);
            bottle = newB + (bottle%c);
            counter+=newB;
        }
        cout << counter << '\n'; 
    }
    return 0;
}
