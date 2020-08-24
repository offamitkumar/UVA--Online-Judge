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
    int b, n; 
    while(cin >> b >> n , b+n){
        vector<int>r(b); 
        for(int i=0; i<b; ++i){
            cin >> r.at(i);
        }
        int u , v, w;
        for(int i=0; i<n;++i){
            cin >> u >> v >> w; 
            --u; --v;
            r[v]+=w; 
            r[u]-=w;
        }
        if(all_of(r.begin(),r.end(),[](int x){return x>=0;})){
            cout<<"S";
        }else{
            cout<<"N";
        }
        cout<<'\n';
    }
    return 0;
}
