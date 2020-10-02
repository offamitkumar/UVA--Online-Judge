#include <bits/stdc++.h>
using namespace std;
#define int int64_t
vector<tuple<int,int,int>>v;
bool compare(tuple<int,int,int>&a, tuple<int,int,int>&b) {
    int penalty1 = (get<1>(b) * get<0>(a)); 
    int penalty2 = (get<1>(a) * get<0>(b));
    if (penalty1 == penalty2) {
        return get<2>(a) < get<2>(b);
    } else {
        return penalty1 < penalty2;
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
    int t; cin >> t; 
    while (t--) {
        v.clear(); 
        int n; cin >> n; 
        for (int i=1,a,b; i<=n; ++i) {
            cin >> a >> b; 
            v.push_back(make_tuple(a,b,i));
        }
        sort(v.begin(), v.end(), compare);
        bool firstTime = true;
        for (auto&[a,b,c]:v) {
            if (!firstTime) {
                cout << ' ';
            }
            firstTime = false;
            cout << c ;
        }
        cout << '\n'; 
        if (t) {
            cout << '\n'; 
        }
    }
    return 0;
}
