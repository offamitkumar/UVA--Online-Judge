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
    for(int tt=1; tt<=t;++tt){
        printf("Test #%ld: ", tt);
        int n;string s; 
        cin >> s >> s; 
        cin >> n;
        vector<vector<int>>dp(n, vector<int>(n));
        for(int i=0; i<n; ++i){
            for(int j=0; j<n;++j){
                cin >> dp[i][j];
//                scanf("%ld",dp[i][j]);
            }
        }
        bool ok = true;
        for(int i=0; i<n;++i){
            for(int j=0;j<n;++j){
                if(dp[i][j] < 0 || dp[i][j]!=dp[n-1-i][n-j-1]){
                    ok = false;
                    goto fast;
                }
            }
        }
fast:
        if(ok){
            printf("Symmetric.");
        }else{
            printf("Non-symmetric.");
        }
        puts("");
    }
    return 0;
}
