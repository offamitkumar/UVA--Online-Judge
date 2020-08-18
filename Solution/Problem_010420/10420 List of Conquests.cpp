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
    int n ; cin >> n; 
    map<string , set<string>>f;
    while(n--){
        string s,ss; cin >> s; 
        cin.ignore();
        getline(cin, ss); 
        f[s].insert(ss);
    }
    for(auto&itr:f){
        cout << itr.first << ' ' << itr.second.size() << '\n';
    }
    return 0;
}
