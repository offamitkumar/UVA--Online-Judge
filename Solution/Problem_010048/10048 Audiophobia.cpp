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
    int c, s, q; 
    int case_counter{1};
    while (cin >> c >> s >> q, c+s+q) {
        if(case_counter != 1) {
            cout << '\n'; 
        }
        cout << "Case #" << case_counter++ << '\n'; 
        vector<vector<int>>arr(c+1, vector<int>(c+1,INT_MAX)); 
        for (int i=0,u,v,d; i<s; ++i) {
            cin >> u >> v >> d; 
            arr[u][v] = d; 
            arr[v][u] = d;
        }
        for(int k=1;k<=c;++k){
            for(int i=1;i<=c;++i){
                for(int j=1;j<=c;++j){
                    if(arr[i][k]!=INT_MAX && arr[k][j] != INT_MAX){
                        arr[i][j] = min(arr[i][j],(int) max(arr[i][k], arr[k][j])); 
                    }
                }
            }
        }
        while (q--) {
            int u, v;  cin >> u >> v;
            if (arr[u][v] == INT_MAX) {
                cout << "no path" << '\n'; 
            } else {
                cout << arr[u][v] << '\n'; 
            }
        }
    }
    return 0;
}
