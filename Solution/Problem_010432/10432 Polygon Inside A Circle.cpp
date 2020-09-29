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
    double r , n; 
    while (cin >> r >> n) {
        double angle = 360 / n;
        double base = 2 * r * sin(angle*M_PI/360); 
        double height = r * cos(angle*M_PI/360); 
        cout << fixed << setprecision(3) << n * 0.5 * base * height << '\n'; 
    }
    return 0;
}
