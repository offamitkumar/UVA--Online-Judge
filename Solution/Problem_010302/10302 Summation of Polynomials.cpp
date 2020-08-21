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
    map<int,int>f; 
    f[0] =0;
    for(int i=1; i<=50000;++i){
        f[i]= f[i-1] + (i*i*i);
    }
    int x; 
    while(cin >> x){
        cout << f[x] << '\n'; 
    }
    return 0;
}
