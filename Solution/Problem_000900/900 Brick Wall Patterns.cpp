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
    vector<int>fib(54); 
    fib[1] = 1; 
    fib[2] = 2;
    for(int i=3; i<=51; ++i){
        fib[i] = fib[i-1] + fib[i-2];
    }
    int t; 
    while(cin >> t , t){
        cout << fib[t] << '\n'; 
    }
    return 0;
}
