#include <bits/stdc++.h>
using namespace std;
#define int int64_t
double ftoc(double c){
    return ((c - 32.0f) * 5.0f / 9.0f); 
}
double ctof(double c){
    return ((9.0f / 5.0f)*c) + 32.0f; 
}
signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    int t; cin >> t; 
    int counter{1};
    while(t--){
        double a , b;  cin >> a >> b; 
        a = ctof(a);
        cout <<"Case " << counter++ << ": ";
        cout << fixed << setprecision(2) << ftoc(a + b) <<  '\n'; 
    }
    return 0;
}
