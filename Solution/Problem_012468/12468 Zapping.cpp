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
    int u , v; 
    while(cin >> u >> v  && (u+v)!=-2){
        cout << min({abs(v-u) , 100-v+u , 100 -u + v}) << '\n';
    }
    return 0;
}
