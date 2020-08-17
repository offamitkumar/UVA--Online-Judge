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
    bool more = false;
    while(cin >> n){
        if(more){cout << '\n';}
        more = true;
        vector<string>V(n);
        unordered_map<string, int> f; 
        string s;
        for(int i=0; i < n ; ++i){
            cin >> s; 
            V[i] = s;
            f[s] =0;
        }
        for(int i=0; i<n;++i){
            cin >> s; 
            int u , v; 
            cin >> u >> v; 
            if(v){
                f[s]-=u;
                f[s]+=(u%v);
            }
            for(int j =0; j < v; ++j){
                cin >> s; 
                f[s] += u/v;
            }
        }
        for(auto&itr:V){
            cout << itr <<' ' << f[itr] << '\n'; 
        }
    }
    return 0;
}
