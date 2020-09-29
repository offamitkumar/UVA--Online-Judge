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
    while (cin >> n && n) {
        vector<int>v(n); 
        for (int i=0; i < n; ++i)  {
            cin >> v.at(i);
        }
        int counter{}; 
        for (int i=0; i<n; ++i) {
            for (int j=i+1; j<n; ++j) {
                counter += (__gcd(v.at(i), v.at(j)) == 1);
            }
        }
        n = (n * (n-1))/2;
        if (!counter) {
            cout << "No estimate for this data set." << '\n'; 
        } else {
            cout << fixed << setprecision(6) << double(sqrt(double(n)/double(counter) * double(6))) << '\n'; 
        }
    }
    return 0;
}
