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
    int n; 
    while(cin >> n , n) {
        int counter{}; 
        while(n>0) {
            counter += (n*n); 
            --n;
        }
        cout << counter << '\n'; 
    }
    return 0;
}
