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
        int n; cin >> n; 
        vector<int>v(n); 
        for(auto&itr:v)cin >> itr; 
        sort(v.begin(), v.end());
        int x = accumulate(v.begin() , v.end() , 0ll);
        vector<vector<bool>>dp(n+1 , vector<bool>(x/2+1));
        // dp[i][j] => can we make sum j with first i elements
        for(int i=0; i<=n; ++i){
            dp[i][0] = true;
        }
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=(x/2); ++j){
                if(dp[i-1][j]){
                    dp[i][j] = true;
                }else if(j>= v.at(i-1)){
                    dp[i][j] = dp[i-1][j-v.at(i-1)];
                }
            }
        }
        int best{INT_MAX};
        for(int i=0;i<=x/2;++i){
            if(dp[n][i]){
                best = min(best , abs(i - (x - i)));
            }
        }
        cout << best << '\n'; 
    }
    return 0;
}
