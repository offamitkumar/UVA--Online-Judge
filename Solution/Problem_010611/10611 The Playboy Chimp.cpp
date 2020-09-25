#include <bits/stdc++.h>
using namespace std;
#define int int64_t
bool compare(int a , int b) {
    return a < b;
}
signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    int n; cin >> n; 
    vector<int>v(n); for(auto&itr:v) cin >> itr;
    sort(v.begin(), v.end()); 
    cin >> n; 
    while (n--) {
        int q; cin >> q; 
        auto itrl = lower_bound(v.begin(), v.end() , q);
        if(itrl-v.begin()-1 < 0) {
            cout << "X ";
        }else{
            cout << v.at(itrl - v.begin()-1) << ' '; 
        }
        auto itru = upper_bound(v.begin(), v.end() , q);
        if(itru == v.end()) {
            cout << "X" << '\n';
        }else{
            cout << v.at(itru - v.begin()) << '\n'; 
        }
    }
    return 0;
}
