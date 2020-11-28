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
    int n,gc{1}; 
    while (cin >> n && n) {
        cout << "Game " << gc++ <<":\n";
        vector<int>v(n); 
        map<int,int>f; 
        for (int i=0; i<n; ++i) {
            cin >> v.at(i); 
            f[v.at(i)]++;
        }
        while(true) {
            map<int,int>k = f,m; 
            int one{}, two{};
            int allzero{0};
            for (int i=0,x; i<n; ++i) {
                cin >> x;
                allzero +=x;
                if (v[i] == x) {
                    one++;
                    k[x]--;
                } else {
                    m[x]++;
                }
            }
            if (!allzero) {
                break;
            }
            for (auto &itr: m) {
                if (k[itr.first]>0) {
                    two += min(m[itr.first], k[itr.first]);
                }
            }
            cout << setfill(' ') << setw(5) << "(" << one << "," << two << ")" << '\n'; 
        }
    }
    return 0;
}
