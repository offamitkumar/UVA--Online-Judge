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
        int a,b; cin >> a >> b; 
        if(a < b || ((a&1)^(b&1))){
            cout <<"impossible" << '\n'; 
        }else{
            cout << (a+b) / 2 << ' '; 
            cout << (a-b) / 2 << '\n'; 
        }
    }
    return 0;
}
