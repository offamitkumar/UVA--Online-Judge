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
    while(cin >> n , n){
        string s; cin >>s ; 
        n = (s.size()/n);
        for(int i=0; i<s.size(); i+=n){
            reverse(s.begin()+i , s.begin()+i+n);
        }
        cout << s << '\n'; 
    }
    return 0;
}
