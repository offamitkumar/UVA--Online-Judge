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
        double n; cin >> n; 
        double a, an;  cin >> a >> an;
        vector<double>v(n); 
        for(auto&itr:v){
            cin >> itr;
        }
        double a1 = n * a + an; 
        for(double i=n-1; i>=0;--i){
            a1-=((2.0 * double(n-i)) * v.at(i));
        }
        cout << fixed  << setprecision(2) << double(a1/double(n+1.0)) << '\n'; 
        if(t){
            cout << '\n'; 
        }
    }
    return 0;
}
