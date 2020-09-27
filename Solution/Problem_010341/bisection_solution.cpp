#include <bits/stdc++.h>
using namespace std;
#define int int64_t
#define EPS 1e-7
long double p,q,r,s,t,u; 
double eval(double x) {
   return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t *(x*x) + u;
}
double bisection(void) {
    double low = 0.0f , high = 1.0f; 
    while (low + EPS < high) {
        double mid = (low + high) /(double)2.0f; 
        if (eval(mid) * eval(low) <= 0) {
            high = mid;
        } else {
            low = mid;
        }
    }
    return (high + low) / (double)2.0f;
}
signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    cout << fixed << setprecision(4);
    while (cin >> p >> q >> r >> s >> t >> u ) {
        if ( eval(0)  * eval(1) > 0) {
            cout << "No solution" << '\n'; 
        } else {
            cout << bisection() << '\n'; 
        }
    }
    return 0;
}
