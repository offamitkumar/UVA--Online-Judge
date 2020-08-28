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
        long double a , b , c; cin >> a >> b >> c;
        long double work = (a + b) / 3.0f; // amount of work that C have to do
        a-=work, b-=work;
        cout << (c /  (a + b))* a << endl;
    }
    return 0;
}
