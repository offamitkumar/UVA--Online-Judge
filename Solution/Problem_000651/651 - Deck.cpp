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
    double n; 
    cout <<"# Cards Overhang"<<'\n'; 
    while(cin >> n){
        double ans{}; 
        for(int i=1; i<=n; ++i){
            ans += 0.5 / double(i); 
        }
        cout << setw(5) << setfill(' ') <<int(n); 
        cout << setw(10) << setfill(' ') << fixed << setprecision(3) << ans << '\n'; 
    }
    return 0;
}
