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
        string a; cin >> a; 
        sort(a.begin() , a.end()); 
        do{
            cout << a << '\n'; 
        }while (next_permutation(a.begin(), a.end()));
        cout << '\n'; 
    }
    return 0;
}
