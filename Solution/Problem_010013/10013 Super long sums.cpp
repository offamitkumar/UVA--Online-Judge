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
        int n; cin >> n; 
        vector<int>a(n) , b(n) , c(n+2); 
        int carry=0;
        for (int i=0; i<n; ++i) {
            cin >> a.at(i) >> b.at(i); 
        }
        for (int i=n-1; i>=0; --i) {
            c[i] = (a[i] + b[i] + carry)%10;
            carry = (a[i] + b[i]+carry)/10;
        }
        if(carry) {
            cout << carry; 
        }
        for (int i=0; i<n; ++i) {
            cout << c[i];
        }
        cout << '\n'; 
        if(t) 
            cout << '\n';
    }
    return 0;
}
