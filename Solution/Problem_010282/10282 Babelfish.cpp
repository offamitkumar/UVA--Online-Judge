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
    string a, b; 
    map<string, string> f;
    while (getline(cin ,a) && a.size()) {
        istringstream ss(a); 
        ss >> a; 
        ss >> b; 
        f[b] = a;
    }
    while (getline(cin ,a)) {
        if (f.find(a) != f.end()) {
            cout << f[a] << '\n'; 
        } else {
            cout << "eh" << '\n'; 
        }
    }
    return 0;
}
