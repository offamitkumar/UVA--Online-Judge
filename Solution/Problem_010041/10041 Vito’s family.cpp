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
        int r; cin >> r; 
        vector<int>v(r); 
        int mx{INT_MIN},mn{INT_MAX};
        for(auto&itr:v){
            cin >> itr;
            mx = max(mx , itr);
            mn = min(mn , itr);
        }
        int sum{INT_MAX};
        for(int i=mn; i<=mx; ++i){
            int temp{};
            for(auto&itr:v){
                temp+=abs(itr-i);
            }
            sum = min(sum , temp);
        }
        cout << sum << '\n'; 
    }
    return 0;
}
