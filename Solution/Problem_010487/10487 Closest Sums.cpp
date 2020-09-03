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
    int counter = 1;
    while(cin >> n && n){
        printf("Case %ld:\n",counter++);
        vector<int>v(n); 
        for(auto&itr:v){cin >> itr;}
        int m,x; cin >> m; 
        while(m--){
            cin >> x;
            int ans = INT_MAX;
            for(int i=0; i<n;++i){
                for(int j=i+1; j<n;++j){
                    int candidate = v.at(i) + v.at(j); 
                    if(abs(x - ans) > abs(x - candidate)){
                        ans = candidate;
                    }
                }
            }
            printf("Closest sum to %ld is %ld.\n",x, ans);
        }
    }
    return 0;
}
