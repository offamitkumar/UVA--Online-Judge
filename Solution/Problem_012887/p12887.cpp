#include <bits/stdc++.h>
using namespace std;
#define int int64_t
int mod = 1e9+7;
signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    vector<int>dp(5005); 
    dp[0]=dp[1]=1;
    for(int i=2; i<dp.size(); ++i) {
        for (int j=0; j<i; ++j) {
            dp[i]+=((dp[j]*dp[i-j-1])%mod);;
            dp[i]%=mod;
        }
    }
    int t; cin >> t; 
    while (t--) {
        int n; cin >> n;
        cout << dp[n] << '\n'; 
    }
    return 0;
}
