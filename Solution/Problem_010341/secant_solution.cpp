#include <bits/stdc++.h>
using namespace std;
#define int int64_t
#define EPS 1e-7
long double p,q,r,s,t,u; 
double eval(double x) {
   return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t *(x*x) + u;
}
double secant(void) {
    if (eval(0) == 0) {
        return 0;
    }
    double x1 =1.0f , x0 = 0.0f;
    while (true) {
        double temp = (eval(x1) * (x1-x0)) / (eval(x1) - eval(x0)); 
        if (fabs(temp) < EPS) {
            return x1; 
        }
        x0 = x1; 
        x1 = x1 - temp;
    }
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
            cout << secant() << '\n'; 
        }
    }
    return 0;
}
